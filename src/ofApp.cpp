#include "ofApp.h"
#include "ofxDelaunay2D.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofBackground(0);
    src.loadImage("source.png");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,250,240);
    ofSetColor(255,255,255);
    src.draw(0,0);
    ofNoFill();
    ofSetColor(0,70,255);
    m_triangulation.drawWireframe();
    
    ofFill();
    for(size_t i=0; i<m_points.size(); ++i) {
        ofSetColor(255,255,255);
        ofCircle(m_points[i].x, m_points[i].y, 4);
        ofSetColor(src.getColor(m_points[i].x, m_points[i].y));
        ofCircle(m_points[i].x, m_points[i].y, 3);
    }
    ofSetColor(0,0,255);
    ofDrawBitmapString("'r' to reset, 'd' to export to clipboard", ofPoint(10,20));
    ofDrawBitmapString(exportmsg,ofPoint(10,33));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'r'){
        m_triangulation.clear();
        m_points.clear();
        exportmsg = "";
    }
    if(key == 'd'){
        ofLog() << "XXXXXXXXXXXXXXXXXXX";
                ofLog() << "XXXXXXXXXXXXXXXXXXX";
                ofLog() << "XXXXXXXXXXXXXXXXXXX";
//        ofLog() << "Test";
//        ofLog(OF_LOG_NOTICE) << m_triangulation.getNumIndices();
        int count = 0;
        for(int i = 0; i < m_triangulation.getNumIndices()/3; i++){
            trigen(
                   m_triangulation.getVertices()[m_triangulation.getIndex(3*i)].x,
                   m_triangulation.getVertices()[m_triangulation.getIndex(3*i)].y,
                   m_triangulation.getVertices()[m_triangulation.getIndex((3*i)+1)].x,
                   m_triangulation.getVertices()[m_triangulation.getIndex((3*i)+1)].y,
                   m_triangulation.getVertices()[m_triangulation.getIndex((3*i)+2)].x,
                   m_triangulation.getVertices()[m_triangulation.getIndex((3*i)+2)].y
                   );
        }
        toClipboard();
    }

}
//--------------------------------------------------------------
void ofApp::trigen(int x1,int y1,int x2,int y2,int x3,int y3){
    //fillTri 269,289,267,259,297,256,'#FBC0B0','#FDEEE7'
    col1 = ofToHex(src.getColor(x1, y1).getHex()).substr(2,8);
    col2 = ofToHex(src.getColor(ofLerp(x2,x3,0.5), ofLerp(y2,y3,0.5)).getHex()).substr(2,8);
    //ofLog() << "fillTri " << x1 << ","<< y1 << ","<< x2 << ","<< y2 << ","<< x3 << ","<< y3 << ",'#"<<col1<<"','#"<<col2<<"'";
    exporttxt += "fillTri " + ofToString(x1) + ","+ ofToString(y1) + ","+ ofToString(x2) + ","+ ofToString(y2) + ","+ ofToString(x3) + ","+ ofToString(y3) + ",'#"+ofToString(col1)+"','#"+ofToString(col2)+"'"+"\n";

}

void ofApp::toClipboard(){
    ofLog() << exporttxt;
    ofSystem("echo \""+exporttxt+"\" | pbcopy");
    exporttxt = "";
    exportmsg = "Exported to clipboard";
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
    m_points.push_back(ofVec2f(x,y));
    m_triangulation = ofxDelaunay2D::triangulate(m_points);
    // printf("indices %d %d\n", m_triangulation.getNumIndices(), m_triangulation.getNumVertices());
    exportmsg = "";
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
