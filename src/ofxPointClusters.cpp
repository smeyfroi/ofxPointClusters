#include "ofxPointClusters.h"

#include <algorithm>

#include "dkm.hpp"

PointClusters::PointClusters() {
  setThreadName("PointClusters " + ofToString(this));
  startThread();
}

PointClusters::~PointClusters() {
  updates.close();
  waitForThread(true);
}

void PointClusters::update() {
  //  updates.send({});
}

void PointClusters::add(glm::vec2 position) {
  ClusterUpdate update { { position } };
  updates.send(update);
}

void PointClusters::setParameterOverrides(const ParameterOverrides& overrides) {
  bool needUpdateSignal = false;

  {
    std::lock_guard<std::mutex> guard(mutex);

    if (parameterOverrides.numClusters == overrides.numClusters &&
        parameterOverrides.maxSourcePoints == overrides.maxSourcePoints) {
      return;
    }

    const ParameterOverrides previous = parameterOverrides;
    updateOverridesLocked(overrides);

    if (previous.numClusters != parameterOverrides.numClusters) {
      needUpdateSignal = true;
    }

    if (previous.maxSourcePoints != parameterOverrides.maxSourcePoints) {
      const int maxPoints = getMaxSourcePointsEffective();
      if (points.size() > static_cast<size_t>(maxPoints)) {
        needUpdateSignal = true;
      }
    }
  }

  if (needUpdateSignal) {
    requestUpdate();
  }
}

void PointClusters::clearParameterOverrides() {
  setParameterOverrides(ParameterOverrides {});
}

void PointClusters::requestUpdate() {
  ClusterUpdate update;
  update.forceUpdate = true;
  updates.send(update);
}

std::vector<glm::vec2> PointClusters::getClusters() {
  std::lock_guard<std::mutex> guard(mutex);
  return clusters;
}

size_t PointClusters::size() {
  std::lock_guard<std::mutex> guard(mutex);
  return clusters.size();
}

int PointClusters::getNumClustersEffective() const {
  if (numClustersOverrideEnabled.load()) {
    return numClustersOverrideValue.load();
  }
  return static_cast<int>(clustersParameter.get());
}

int PointClusters::getMaxSourcePointsEffective() const {
  if (maxSourcePointsOverrideEnabled.load()) {
    return maxSourcePointsOverrideValue.load();
  }
  return maxSourcePointsParameter.get();
}

void PointClusters::updateOverridesLocked(const ParameterOverrides& overrides) {
  parameterOverrides = overrides;

  if (parameterOverrides.numClusters.has_value()) {
    numClustersOverrideEnabled.store(true);
    numClustersOverrideValue.store(parameterOverrides.numClusters.value());
  } else {
    numClustersOverrideEnabled.store(false);
  }

  if (parameterOverrides.maxSourcePoints.has_value()) {
    maxSourcePointsOverrideEnabled.store(true);
    maxSourcePointsOverrideValue.store(parameterOverrides.maxSourcePoints.value());
  } else {
    maxSourcePointsOverrideEnabled.store(false);
  }
}

void PointClusters::updateClusters() {
  const int numClusters = getNumClustersEffective();
  if (numClusters <= 0) return;
  if (points.size() < static_cast<size_t>(numClusters)) return;

  std::tuple<std::vector<std::array<float, 2>>, std::vector<uint32_t>> clusterResults;
  dkm::clustering_parameters<float> params { static_cast<uint32_t>(numClusters) };
  params.set_random_seed(1000); // keep clusters stable
  clusterResults = dkm::kmeans_lloyd(points, params);

  clusters.clear();
  for (const auto& cluster : std::get<0>(clusterResults)) {
    float x = cluster[0];
    float y = cluster[1];
    clusters.emplace_back(glm::vec2 { x, y });
  }
}

void PointClusters::threadedFunction() {
  ClusterUpdate update;
  while (updates.receive(update)) {
    std::lock_guard<std::mutex> guard(mutex);

    bool needUpdate = false;

    // Add points and consume any pending updates.
    do {
      if (update.forceUpdate) {
        needUpdate = true;
      }

      std::for_each(update.newPoints.begin(), update.newPoints.end(), [&](auto& p) {
        points.push_back(std::array<float, 2> { p.x, p.y });
        needUpdate = true;
      });
    } while (updates.tryReceive(update));

    // Erase oldest 5% of the max.
    const int maxPoints = getMaxSourcePointsEffective();
    if (maxPoints > 0 && points.size() > static_cast<size_t>(maxPoints)) {
      const int eraseCount = std::max(1, maxPoints * 5 / 100);
      const size_t eraseCountClamped = std::min(points.size(), static_cast<size_t>(eraseCount));
      points.erase(points.begin(), points.begin() + eraseCountClamped);
      needUpdate = true;
    }

    if (needUpdate) {
      updateClusters();
    }
  }
}

int PointClusters::getNumClusters() const {
  return getNumClustersEffective();
}

int PointClusters::getMinClusters() const {
  return static_cast<int>(clustersParameter.getMin());
}

int PointClusters::getMaxClusters() const {
  return static_cast<int>(clustersParameter.getMax());
}

ofParameterGroup& PointClusters::getParameterGroup() {
  if (parameters.size() == 0) {
    parameters.setName(getParameterGroupName());
    parameters.add(maxSourcePointsParameter);
    parameters.add(clustersParameter);
  }
  return parameters;
}
