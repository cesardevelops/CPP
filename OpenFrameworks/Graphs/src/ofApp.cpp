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
float counter = 0;
vector<int> countsVector;
int biggestWord;
string filecontents;

void rm_nl(string &s)
    {
        for (int p = s.find("\n"); p != (int) string::npos; p = s.find("\n"))
            {
                s.erase(p,1);
            }
    }

vector<int> CountWords(string myString)
    {
        //https://tinyurl.com/3bjkzt45
        //Remove unnecessary elements
        myString.erase(std::remove(myString.begin(), myString.end(), '\n'), myString.end());
        myString.erase(std::remove(myString.begin(), myString.end(), ','), myString.end());
        myString.erase(std::remove(myString.begin(), myString.end(), '.'), myString.end());
        //Separate the words
        vector<string> splitString = ofSplitString( myString, " ");
        //count the size of the words
        vector<int> countsVector(1);
        string currentString;
        int newSize = 0;
        for(int i = 0; i < splitString.size(); i++)
            {
                currentString = splitString[i];
                if(currentString.length() + 1 > countsVector.size())
                    {
                        countsVector.resize(currentString.length()+1, 0);
                    }
                countsVector.at(currentString.length()) += 1;

            }
        //return the word counts.
        return countsVector;
    }

int GetBiggestInt(vector<int> counts)
    {
        int max = 0;
        for(int i = 0; i < counts.size(); i++)
            {
                if(max<counts[i])
                    {
                        max = counts[i];
                    }
            }
        return max;
    }

string ReadFile(string path)
    {
        ofFile file;
        file.open(ofToDataPath(path), ofFile::ReadWrite, false);
        ofBuffer buff = file.readToBuffer();
        return buff.getText();
    }

//--------------------------------------------------------------
void ofApp::setup()
    {
        //ofEnableSmoothing();
        
        filecontents = ReadFile("textfile.txt");
        //vector<int> counts = CountWords(filecontents);
        countsVector = CountWords(filecontents);
        biggestWord = GetBiggestInt(countsVector);
        //cout << biggestWord << endl;
        
        /*
        for(int i=0; i < counts.size(); i++)
            {
                cout << "Words of size " << i << ": " << counts[i] << endl;
            }
        */
    }

//--------------------------------------------------------------
void ofApp::update()
    {
        

    }

//--------------------------------------------------------------
void DrawRectangle(int wordSize, int wordCount, int maxWordSize, int totalColumns)
    {
        float redfactor = 255 / maxWordSize;
        float redColor = redfactor * wordCount;
        float offsetForColumns = 20;
        //Rectangle
        ofRectangle rect;
        rect.x = 15 * wordSize;
        rect.y = ofGetWindowHeight() - (10 * wordCount) - offsetForColumns;
        rect.width = 15;
        rect.height = 10 * wordCount;
        ofSetColor(redColor, 0, 0);
        ofDrawRectangle(rect);
        //Text
        ofSetColor(255, 255, 255);
        ofDrawBitmapString(to_string(wordCount), rect.x, rect.y);
    }

void ofApp::draw()
    {
        ofDrawBitmapString(filecontents, 0, 0);
        for(int i = 1; i < countsVector.size(); i++)
            {
                DrawRectangle(i, countsVector[i], biggestWord, countsVector.size());
            }
        
        xmouse = ofGetMouseX();
        ymouse = ofGetMouseY();
        counter = counter + (0.01 * ofGetFrameRate());
        string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
        //ofDrawBitmapString(fpsStr, 100,100);
        //ofDrawBitmapStringHighlight("Everything works!", counter, counter);
        ofDrawBitmapStringHighlight(to_string(xmouse) +", " + to_string(ymouse), xmouse, ymouse);
        //ofDrawBitmapStringHighlight("Hello World", xmouse, ymouse);
        //ofDrawBitmapStringHighlight(to_string(ofGetWindowWidth()), xmouse, ymouse);
        
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
