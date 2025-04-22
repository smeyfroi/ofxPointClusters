#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(ofFloatColor{0.0, 0.0, 0.0, 1.0});

  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>();
  audioDataProcessorPtr = std::make_shared<ofxAudioData::Processor>(audioAnalysisClientPtr);

  introspector.setVisible(true);
  
  auto& clusterParameters = pointClusters.getParameterGroup();
  parameters.add(clusterParameters);
  gui.setup(parameters);
}

//--------------------------------------------------------------
void ofApp::update(){
  introspector.update();

  audioDataProcessorPtr->update();
  float s = audioDataProcessorPtr->getNormalisedScalarValue(ofxAudioAnalysisClient::AnalysisScalar::pitch);
  float t = audioDataProcessorPtr->getNormalisedScalarValue(ofxAudioAnalysisClient::AnalysisScalar::rootMeanSquare);

  std::vector<ofxAudioData::ValiditySpec> sampleValiditySpecs {
    {ofxAudioAnalysisClient::AnalysisScalar::rootMeanSquare, false, 0.01},
    {ofxAudioAnalysisClient::AnalysisScalar::pitch, false, 50},
    {ofxAudioAnalysisClient::AnalysisScalar::pitch, true, 3000}
  };
  
  if (audioDataProcessorPtr->isDataValid(sampleValiditySpecs)) {
    float tMA = audioDataProcessorPtr->getNormalisedScalarValueMA(ofxAudioAnalysisClient::AnalysisScalar::rootMeanSquare);
    if (t > tMA) {
      introspector.addCircle(s, t, 3.0/ofGetWindowWidth(), ofColor::yellow, true, 5); // introspection: small yellow circle for new raw source sample
      pointClusters.add({s, t});
    }
  }
  
  pointClusters.update();

  for (const auto& c : pointClusters.getClusters()) {
    introspector.addCircle(c.x, c.y, 5.0/ofGetWindowWidth(), ofColor::red, true, 3); // introspection: medium red circle for cluster
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  introspector.draw(ofGetWindowWidth());
  gui.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){
  audioAnalysisClientPtr->closeStream();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (audioAnalysisClientPtr->keyPressed(key)) return;
  if (introspector.keyPressed(key)) return;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
