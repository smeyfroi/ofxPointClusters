#pragma once

#include <array>
#include <atomic>
#include <optional>
#include <string>
#include <vector>

#include "ofMain.h"
#include "ofParameter.h"

struct ClusterUpdate {
  std::vector<glm::vec2> newPoints;
  bool forceUpdate = false;
};

class PointClusters : public ofThread {

public:
  struct ParameterOverrides {
    std::optional<int> numClusters;
    std::optional<int> maxSourcePoints;
  };

  PointClusters();
  ~PointClusters();
  void update();
  void add(glm::vec2 position);

  void setParameterOverrides(const ParameterOverrides& overrides);
  void clearParameterOverrides();

  size_t size();
  int getNumClusters() const;
  int getMinClusters() const;
  int getMaxClusters() const;
  std::vector<glm::vec2> getClusters();

  std::string getParameterGroupName() const { return "Point Clusters"; }
  ofParameterGroup parameters;
  ofParameter<int> maxSourcePointsParameter { "Max Source Points", 2000, 20, 96000 }; // Note: we only use "valid" samples. Floor 20 keeps clustering stable for typical cluster counts (max 17) while letting the VideoFast preset's 40 land correctly without parameter-floor clamping. Floor history: 500 → 50 → 20.
  ofParameter<float> clustersParameter { "Clusters", 5.0, 2.0, 17.0 };
  ofParameterGroup& getParameterGroup();

protected:
  void threadedFunction() override;

private:
  void requestUpdate();

  std::vector<glm::vec2> clusters;
  std::vector<std::array<float, 2>> points; // array type to suit dkm library
  ofThreadChannel<ClusterUpdate> updates;

  ParameterOverrides parameterOverrides;
  std::atomic<bool> numClustersOverrideEnabled { false };
  std::atomic<int> numClustersOverrideValue { 0 };
  std::atomic<bool> maxSourcePointsOverrideEnabled { false };
  std::atomic<int> maxSourcePointsOverrideValue { 0 };

  int getNumClustersEffective() const;
  int getMaxSourcePointsEffective() const;

  void updateOverridesLocked(const ParameterOverrides& overrides);
  void updateClusters();
};
