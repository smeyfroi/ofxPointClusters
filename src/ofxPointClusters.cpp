#include "ofxPointClusters.h"
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
  updates.send({});
}

void PointClusters::add(glm::vec2 position) {
  ClusterUpdate update { {position} };
  updates.send(update);
}

std::vector<glm::vec2> PointClusters::getClusters() {
  lock();
  auto result = clusters;
  unlock();
  return result;
}

void PointClusters::updateClusters() {
  if (points.size() < clustersParameter) return;
  
  std::tuple<std::vector<std::array<float, 2>>, std::vector<uint32_t>> clusterResults;
  dkm::clustering_parameters<float> params { static_cast<uint32_t>(clustersParameter) };
  params.set_random_seed(1000); // keep clusters stable
  clusterResults = dkm::kmeans_lloyd(points, params);

  clusters.clear();
  for (const auto& cluster : std::get<0>(clusterResults)) {
    float x = cluster[0]; float y = cluster[1];
    clusters.emplace_back(glm::vec2 {x, y});
  }
}

void PointClusters::threadedFunction() {
  ClusterUpdate update;
  while (updates.receive(update)) {
    lock();
    
    // add new points
    do {
      std::for_each(update.newPoints.begin(),
                    update.newPoints.end(),
                    [&] (auto& p) { points.push_back(std::array<float, 2> {p.x, p.y}); });
    } while(updates.tryReceive(update));

    // erase oldest 5% of the max
    if (points.size() > maxSourcePointsParameter) {
      points.erase(points.begin(), points.begin() + maxSourcePointsParameter*5/100);
    }
    
    updateClusters();

    unlock();
  }
}

ofParameterGroup& PointClusters::getParameterGroup() {
  if (parameters.size() == 0) {
    parameters.setName(getParameterGroupName());
    parameters.add(maxSourcePointsParameter);
    parameters.add(clustersParameter);
  }
  return parameters;
}
