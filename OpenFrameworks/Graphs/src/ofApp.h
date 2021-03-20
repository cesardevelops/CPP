#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        //my variables
        ofFile myTextFile;
        int xmouse = 0;
        int ymouse = 0;
    
        //Variables used both on update() and draw()
        int biggestCount;
        float textypos = 0;
        float counter = 0;
        string filepath = "textfile03.txt";
        string filecontents;
        vector<int> countsVector;
		
};
