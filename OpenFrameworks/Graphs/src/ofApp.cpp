//https://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofDrawBitmapString
//https://openframeworks.cc/documentation/ofxAssimpModelLoader/ofxAssimpModelLoader/
//https://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofDrawLine
//https://openframeworks.cc/ofBook/chapters/how_of_works.html
//https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/

#include "ofApp.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

float counter = 0;
//int xmouse = 0;
//int ymouse = 0;

void CountWords()
    {
        string myString = "The young “doctor” showed his determination early on when he faced a whopping 27 rejections from book publishers for his first children’s book And To Think That I Saw It On Mulberry Street. One day, when he was walking down the street, he literally ran into an old classmate who";

        // divide the string using a ';' as a delimiter
        // notice that i removed the spaces after the individual words
        vector<string> splitString = ofSplitString( myString, " ");

        // loop through the results
        //vector<int> counts(100, 0);
        vector<int> counts;
        string current;
        
        for(int i=0; i < splitString.size(); i++)
            {
                //cout << splitString[i] << endl;
                current = splitString[i];
                
                if(current.size() > counts.size() )
                    {
                        //int growTimes = current.size() - counts.size();
                        counts.resize(current.size());
                        counts[current.size()] += 1;
                    }
                else
                    {
                        counts[current.size()] += 1;
                    }
                
            }
        
        for(int i=0; i < counts.size(); i++)
            {
                cout << counts[i] << endl;
            }
        
    }

void SplitStringB()
    {
        string myString = "The young “doctor” showed his determination early on when he faced a whopping 27 rejections from book publishers for his first children’s book And To Think That I Saw It On Mulberry Street. One day, when he was walking down the street, he literally ran into an old classmate who";

        // divide the string using a ';' as a delimiter
        // notice that i removed the spaces after the individual words
        vector<string> splitString = ofSplitString( myString, " ");

        // loop through the results
        vector<int> counts(100, 0);
        string current;
        
        for(int i=0; i < splitString.size(); i++)
            {
                //cout << splitString[i] << endl;
                current = splitString[i];
                counts[current.size()] += 1;
            }
        
        for(int i=0; i < counts.size(); i++)
            {
                cout << counts[i] << endl;
            }
        
    }
//--------------------------------------------------------------
void ofApp::setup()
    {
        ofEnableSmoothing();
        
        //open text file
        myTextFile.open("textfile.txt",ofFile::WriteOnly);
        myTextFile << "some text written once using setup.";
        CountWords();
        
    }

//--------------------------------------------------------------
void ofApp::update()
    {
        

    }

//--------------------------------------------------------------
void ofApp::draw(){
    
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
