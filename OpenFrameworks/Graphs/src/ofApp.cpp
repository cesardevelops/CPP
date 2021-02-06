//https://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofDrawBitmapString
//https://openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader/
//https://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofDrawLine
//https://openframeworks.cc/ofBook/chapters/how_of_works.html

#include "ofApp.h"
#include <string>
using namespace std;

float counter=0;
//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int xmouse = ofGetMouseX();
    int ymouse = ofGetMouseY();
    counter = counter + (0.01 * ofGetFrameRate());
    string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
    //ofDrawBitmapString(fpsStr, 100,100);
    //ofDrawBitmapStringHighlight("Everything works!", counter, counter);
    ofDrawBitmapStringHighlight("Everything works!", xmouse, ymouse);
    
    glm::vec3 p;      // create a point P
       p.x = 10;       // set the x of the point
       p.y = 10;       // set the y of the point

       ofDrawRectangle(p, 80, 80); // Draw the rectangle
    ofDrawLine(100,100,200,200);
    
    ofRectangle myRect;
        myRect.x = 300;
        myRect.y = 300;
        myRect.width = 100;
        myRect.height = 100;

        ofDrawRectRounded(myRect, 10);
    
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
      ofVertex(400,135);
      ofVertex(215,135);
      ofVertex(365,25);
      ofVertex(305,200);
      ofVertex(250,25);
    ofEndShape();
    
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
