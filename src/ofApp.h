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
        void trigen(int x1,int y1,int x2,int y2,int x3,int y3);
        void toClipboard();
protected:
    ofMesh m_triangulation;
    vector<ofVec2f> m_points;
    ofImage src;
    string col1,col2;
    string exporttxt;
    string exportmsg;
};
