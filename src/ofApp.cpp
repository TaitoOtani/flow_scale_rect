#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    camera.setup(320,240);
    curFlow = &fb;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    
    if(camera.isFrameNew()){
        curFlow= &fb;
        fb.setPyramidScale(0.5);
        fb.setNumLevels(4);
        fb.setWindowSize(32);
        fb.setNumIterations(2);
        fb.setPolyN(7);
        fb.setUseGaussian(false);
        curFlow->calcOpticalFlow(camera);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    ofTranslate(250, 100);
    ofFill();
    ofSetLineWidth(1);
//    camera.draw(0,0,640,480);
    curFlow->draw(0,0,640,480);
    ofPopMatrix();
    
    ofVec2f vec = fb.getAverageFlow()*100;
    
    ofPushMatrix();
    ofNoFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetLineWidth(10);
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    ofDrawRectangle(0, 0, vec.x , vec.y);
    
    ofDrawRectangle(0, 0, vec.y, vec.x);
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
