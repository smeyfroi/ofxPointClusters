#pragma once

#include "ofMain.h"
#include "ofParameter.h"

struct ClusterUpdate {
  std::vector<glm::vec2> newPoints;
};

class PointClusters: public ofThread {

public:
  PointClusters();
  ~PointClusters();
  void update();
  void add(glm::vec2 position);
  size_t size() const { return clusters.size(); };
  std::vector<glm::vec2> getClusters();
  
  std::string getParameterGroupName() const { return "Point Clusters"; }
  ofParameterGroup parameters;
  ofParameter<int> maxSourcePointsParameter { "maxSourcePointsParameter", 4000, 1000, 96000 }; // Note: 1600 raw samples per frame at 30fps, 48K sample-rate
  ofParameter<int> clustersParameter { "clustersParameter", 5, 3, 20 };
  ofParameterGroup& getParameterGroup();

protected:
  void threadedFunction() override;

private:
  std::vector<glm::vec2> clusters;
  std::vector<std::array<float, 2>> points; // array type to suit dkm library
  ofThreadChannel<ClusterUpdate> updates;
  
  void updateClusters();
};
