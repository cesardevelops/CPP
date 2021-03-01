//Code by: CESAR ALEJANDRO MONTERO OROZCO

// LEARNING REFERENCES
//https://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofDrawBitmapString
//https://openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader/
//https://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofDrawLine
//https://openframeworks.cc/ofBook/chapters/how_of_works.html
//https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
//https://openframeworks.cc/ofBook/chapters/shaders.html

#include "ofApp.h"
#include "textParsing.hpp"
#include "textParsing.hpp"

#include <string>

using namespace std;


//This draws a rectangle
void DrawRectangle(int wordSize, int wordCount, int biggestCount, int totalColumns){
    //color calculation
    float redColor = (255 * wordCount) / biggestCount;
    
    //size calculations
    float offsetForColumns = 20;
    float sizefactor = 400 / biggestCount;
    float columnSize = (400 * wordCount) / biggestCount;
    
    ofRectangle rect;
    rect.x = 15 * wordSize;
    rect.y = ofGetWindowHeight() - (columnSize) - offsetForColumns;
    rect.width = 15;
    rect.height = columnSize;
    ofSetColor(redColor, 0, 0);
    ofDrawRectangle(rect);
    //Text
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(to_string(wordCount), rect.x, rect.y);

}

//---------------------------------------------OPEN FRAMEWORKS GRAPHIC SETUP--------------------------------->

//OpenFrameworks function. It runs once, great for getting values ready prior to drawing
void ofApp::setup(){
    filecontents = ReadFile(filepath);
    countsVector = CountWords(filecontents);
    biggestCount = GetBiggestInt(countsVector);
}


void ofApp::update(){
    
}

//OpenFrameworks function. It runs each frame.
void ofApp::draw(){
    textypos += ofGetLastFrameTime() * 5;
    ofSetColor(200, 200, 200);
    ofDrawBitmapString(filecontents, 350, textypos);
    //Draw each vertical rectangle representing the word count
    for(int i = 1; i < countsVector.size(); i++){
            DrawRectangle(i, countsVector[i], biggestCount, countsVector.size());
    }
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
