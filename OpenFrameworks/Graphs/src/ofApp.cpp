//------APENDIX / REFERENCES
//https://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofDrawBitmapString
//https://openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader/
//https://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofDrawLine
//https://openframeworks.cc/ofBook/chapters/how_of_works.html
//https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
//https://openframeworks.cc/ofBook/chapters/shaders.html

#include "ofApp.h"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//Variables used both on update() and draw()
int biggestCount;
float textypos = 0;
float counter = 0;
string filepath = "textfile06.txt";
string filecontents;
vector<int> countsVector;

//Removes a new line in a string. Function not in used, copied from internet.
//I left it here hecause I want ot learn how this works later.
void rm_nl(string &s){
    for (int p = s.find("\n"); p != (int) string::npos; p = s.find("\n")){
        s.erase(p, 1);
    }
}

//removes a single character fro a string
void RemoveChar(string &myString, char &char_to_remove){
    //Explanation of this line of code can be found here: https://tinyurl.com/3bjkzt45
    myString.erase(std::remove(myString.begin(), myString.end(), char_to_remove), myString.end());
}

//removes characters from a string
void RemoveCharacters(string &myString, vector<char> &list){
    for(int i = 0; i < list.size(); i++){
        RemoveChar(myString, list.at(i));
    }
}


//counts how many words of size X exist in a string.
vector<int> CountWords(string myString){
    vector<char> remove_list = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '\n', '{', '}', ':', '"', ',', '?', '.', '<', '>', '^'};
    RemoveCharacters(myString, remove_list); //Remove unnecessary characters
    vector<string> splitString = ofSplitString( myString, " "); //Separate text into a vector containing words.
    vector<int> countsVector(1);
    string currentString;
    int newSize = 0;
    //Counts the size each word, and adds +1 on a vector keeping score of all word sizes.
    for(int i = 0; i < splitString.size(); i++){
        currentString = splitString[i];
        //Extends the vector if the current size is not enough to store a word of this size.
        if(currentString.length() + 1 > countsVector.size()){
            countsVector.resize(currentString.length() + 1, 0);
        }
        countsVector.at(currentString.length()) += 1;
    }
    return countsVector;     //return the word counts.
}

// returns the biggest in from a vector
int GetBiggestInt(vector<int> &counts){
    int max = 0;
    //Reads each item in a vector and keeps the biggest one.
    for(int i = 0; i < counts.size(); i++){
        if(max<counts[i]){
            max = counts[i];
        }
    }
    return max;
}

//reads a file by passing it it the path to it.
string ReadFile(string &path){
    ofFile file;
    file.open(ofToDataPath(path), ofFile::ReadWrite, false);
    ofBuffer buff = file.readToBuffer();
    return buff.getText();
}

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
