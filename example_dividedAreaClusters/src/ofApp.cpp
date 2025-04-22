#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(ofFloatColor{0.0, 0.0, 0.0, 1.0});

  const std::filesystem::path rootSourceMaterialPath { "/Users/steve/Documents/music-source-material" };
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250207-violin-busy-trill.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250207-violin-chord-double-stop-trill.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250207-violin-extreme-dynamic-extreme-range.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250207-violin-melody-double-stop-string-crossing-pizzicato-texture-extreme-dynamic-extreme-range-tremolo.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250207-violin-separate-scale-harmonics-vibrato-string-crossing.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250207-violin-sparse-separate-glissando-pizzicato.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250207-violin-sparse-separate-harmonics.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250207-viola-stepwise-scale-harmonics-vibrato-no-vibrato.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250207-viola-stepwise-open-strings-string-crossing-pizzicato-staccato.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250207-violin-texture-tremolo-bartok-pizzicato-trill-col-legno-pizzicato-ricochet.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250207-violin-warm-stepwise-melody-vibrato.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-glissando-melody-clipped.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-melody.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-same-note-2.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-same-note-3.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-same-note.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale-flutter-tongue-clipped.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale-flutter-tongue-mute-harmon-mute-stem-in.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale-flutter-tongue-mute-harmon-mute-stem-out.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale-mouthpiece-quiet.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale-mute-2.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale-mute-3.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale-mute-harmon-mute-stem-out.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale-mute-plunger-mute-clipped.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale-mute-practice-mute-quiet.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale-mute-quiet.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale-mute.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-scale.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-stepwise-scale.wav");
  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-separate-stepwise.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-trombone-video-melody-long-clipped-flutter-tongue.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-viola-separate-same.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-violin-separate-scale-vibrato-harmonics.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-violin-separate-slow-experiment.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-violin-talking-chromatic-scale.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-violin-trombone-duet-melody.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-violin-video-melody-2.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-violin-video-melody.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-violin-video-separate-scale-quiet-harmonics-2.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-violin-video-separate-scale-quiet-harmonics.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"20250208-violin-video-separate-scale.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"bells-descending-peal.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"harry-guitar.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"ioana-prokofiev.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"Nightsong.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>(rootSourceMaterialPath/"Treganna.wav");
//  audioAnalysisClientPtr = std::make_shared<ofxAudioAnalysisClient::LocalGistClient>();
  audioDataProcessorPtr = std::make_shared<ofxAudioData::Processor>(audioAnalysisClientPtr);
  std::vector<ofxAudioData::ValiditySpec> sampleValiditySpecs {
    {ofxAudioAnalysisClient::AnalysisScalar::rootMeanSquare, false, 0.01},
    {ofxAudioAnalysisClient::AnalysisScalar::pitch, false, 50},
    {ofxAudioAnalysisClient::AnalysisScalar::pitch, true, 3000}
  };
  audioDataProcessorPtr->setValiditySpecs(std::make_unique<ofxAudioData::ValiditySpecs>(sampleValiditySpecs));
  
  auto& clusterParameters = pointClusters.getParameterGroup();
  parameters.add(clusterParameters);

  introspector.setVisible(true);
  gui.setup(parameters);
}

//--------------------------------------------------------------
void ofApp::update(){
  introspector.update();

  audioDataProcessorPtr->update();
  if (audioDataProcessorPtr->isDataValid()) {
    float s = audioDataProcessorPtr->getNormalisedScalarValue(ofxAudioAnalysisClient::AnalysisScalar::pitch, 50, 500, true); // false == not linear
    float t = audioDataProcessorPtr->getNormalisedScalarValue(ofxAudioAnalysisClient::AnalysisScalar::rootMeanSquare, true);
    glm::vec2 currentRawPoint { s, t };
    
//    float tMA = audioDataProcessorPtr->getNormalisedScalarValueMA(ofxAudioAnalysisClient::AnalysisScalar::rootMeanSquare);
//    if (t > tMA) {
      introspector.addCircle(s, t, 3.0/ofGetWindowWidth(), ofColor::yellow, true, 5); // introspection: small yellow circle for new raw source sample
      pointClusters.add(currentRawPoint);
      pointClusters.update();
//    }

    if (lastRawPoint.x >= 0.0) {
      dividedArea.addConstrainedDividerLine(lastRawPoint, currentRawPoint);
    }
    lastRawPoint = currentRawPoint;
  }
  
  const auto& clusters = pointClusters.getClusters();
  bool majorDividersChanged = dividedArea.updateUnconstrainedDividerLines(clusters);
  if (dividedArea.constrainedDividerLines.size() > 5000) {
    dividedArea.deleteEarlyConstrainedDividerLines(50);
  }
  for (const auto& c : clusters) {
    introspector.addCircle(c.x, c.y, 5.0/ofGetWindowWidth(), ofColor::red, true, 2); // introspection: medium red circle for cluster
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  introspector.draw(ofGetWindowWidth());
  ofSetColor(ofColor::white);
  dividedArea.draw(0.0, 5.0/ofGetWindowWidth(), 1.0/ofGetWindowWidth(), ofGetWindowWidth());
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
