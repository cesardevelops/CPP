//https://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofDrawBitmapString
//https://openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader/
//https://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofDrawLine
//https://openframeworks.cc/ofBook/chapters/how_of_works.html
//https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/

#include "ofApp.h"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

float counter = 0;

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
        myString.erase(std::remove(myString.begin(), myString.end(), '\n'), myString.end());
        myString.erase(std::remove(myString.begin(), myString.end(), ','), myString.end());
        myString.erase(std::remove(myString.begin(), myString.end(), '.'), myString.end());
        
        vector<string> splitString = ofSplitString( myString, " ");
        //vector<int> countsVector(100);
        vector<int> countsVector(1);
        string currentString;
        int newSize = 0;
        for(int i = 0; i < splitString.size(); i++)
            {
                currentString = splitString[i];
                // "a" has lenght of 1 and requires a vector of 2
                // if lenght( of 1) > size( of 1)
                if(currentString.length() + 1 > countsVector.size())
                    {
                        cout << "Word: " << currentString << " ";
                        cout << "CurrentString.lenght() :" <<currentString.length() << " ";
                        cout << "countsVector.size() :" <<currentString.length() << endl;
                        newSize = currentString.length()+1;
                        cout << "new size: " << newSize << endl;
                        //countsVector.resize(newSize, 0);
                        countsVector.resize(currentString.length()+1, 0);
                        cout << "Resizing... "<<"countsVector.size() :" << countsVector.size() << endl << endl;
                        //countsVector.push_back(0);
                        
                    }
                    countsVector.at(currentString.length()) += 1;
                    //countsVector.at(currentString.length()) += 1;
                //cout << "Current String Lenght: " << currentString.length() <<endl;
                //cout << "Current Vector Size: " << countsVector.size() << endl;
            }

        
        for(int i = 0; i < countsVector.size(); i++)
            {
                cout << "Words of size " << i << ": " << countsVector[i] << endl;
            }
        
        //cout << "Current String: " << currentString << " size: " << currentString.size() << endl;
        //cout << "Vector Size: " << countsVector.size() << endl;
        return countsVector;
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
        
        
        string filecontents = ReadFile("textfile.txt");
        
        vector<int> counts = CountWords(filecontents);
        
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
void ofApp::draw(){
    /*
    xmouse = ofGetMouseX();
    ymouse = ofGetMouseY();
    counter = counter + (0.01 * ofGetFrameRate());
    string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
    //ofDrawBitmapString(fpsStr, 100,100);
    //ofDrawBitmapStringHighlight("Everything works!", counter, counter);
    //ofDrawBitmapStringHighlight("Everything works!", xmouse, ymouse);
    ofDrawBitmapStringHighlight("Hello World", xmouse, ymouse);
    
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
    */
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
