#pragma once

#include "ofMain.h"
#include "ofxDraggable.h"


class ofxDraggableBezier : public ofxDraggable{
private:
    ofPoint bezierPoint[4];
    float radius[4] = {20,20,10,10};
    int bezierPointNum = 4;
    ofPoint currentPoint;
public:
    ofxDraggableBezier() : ofxDraggable(){
        ofRegisterMouseEvents(this);
        ofRegisterKeyEvents(this);
    };
    
    void draw(ofEventArgs & drawArgs){
        if(!isShow) return;
        //ofxDraggable::draw(drawArgs);
        drawBezierCurve();
    };
    float param = 0;
    float expand = 0;
    void drawBezierCurve(){
        
        ofPushStyle();
        ofPoint controlPoint0 = bezierPoint[0] + expand*(bezierPoint[2]-bezierPoint[0]);
        ofPoint controlPoint1 = bezierPoint[1] + expand*(bezierPoint[3]-bezierPoint[1]);
        currentPoint = ofBezierPoint(bezierPoint[0], controlPoint0, controlPoint1, bezierPoint[1], param);
        ofxDraggable::drawLight(currentPoint);
        
        ofNoFill();
        if(ofxDraggable::isPressed)
            drawBezierPoint(bezierPoint[0], bezierPoint[1],controlPoint0, controlPoint1);
        
        ofSetColor(ofColor::gray);
//        if(ofxDraggable::isPressed){
            ofSetColor(0);
            ofDrawBezier(bezierPoint[0].x, bezierPoint[0].y,
                         controlPoint0.x,  controlPoint0.y,
                         controlPoint1.x,  controlPoint1.y,
                         bezierPoint[1].x, bezierPoint[1].y);
//        }
        ofPopStyle();
    };
    void drawBezierPoint(ofPoint s, ofPoint e, ofPoint c0, ofPoint c1){
        if(ofxDraggable::isPressed ) ofSetLineWidth(5);
        else ofSetLineWidth(1);
        vector<ofColor> colors {ofColor(200,0,0),ofColor(0,0,200),ofColor::gray,ofColor::gray};
        for(auto i:{0,1,2,3}){
            ofSetColor(colors[i]);
            ofDrawCircle(bezierPoint[i],radius[i]);
        }
        ofDrawLine(bezierPoint[0], bezierPoint[2]);
        ofDrawLine(bezierPoint[1], bezierPoint[3]);
    }
    ofPoint getCurrentPoint(){
        return currentPoint;
    }
    
    //event
    bool selected[4] = {false,false,false, false};
    void mousePressed(ofMouseEventArgs &mouse) {
        ofxDraggable::mousePressed(mouse);
        for(int i=0; i<bezierPointNum; i++) {
            if(mouse.distance(bezierPoint[i]) < radius[i] && ofxDraggable::isPressed) {
//                selected[i] = !selected[i];
                selected[i] = true;
            }
        }
    }
    void mouseMoved(ofMouseEventArgs &mouse) {}
    void mouseDragged(ofMouseEventArgs &mouse) {
        for(int i=0; i<bezierPointNum; i++) {
            if(selected[i]) {
                bezierPoint[i] = mouse;
                break;
            }
        }
    }
    void mouseReleased(ofMouseEventArgs &mouse) {
        for(int i=0; i<bezierPointNum; i++) {
            selected[i] = false;
        }
    }
    void mouseScrolled(ofMouseEventArgs &mouse) {}
    void mouseEntered(ofMouseEventArgs &mouse) {}
    void mouseExited(ofMouseEventArgs &mouse) {}
    void keyPressed(ofKeyEventArgs &keyArgs) {}
    void keyReleased(ofKeyEventArgs &keyArgs) {
        if(keyArgs.key == ofxDraggable::key) {
            //ofxDraggable::isPressed = false;
        }
    }
    
    void show(bool b){
        ofxDraggable::show(b);
    }
    
    
    void setStartPoint(ofPoint p){
        bezierPoint[0] = p;
    };
    ofPoint getStartPoint(){
        return bezierPoint[0];
    };
    void setEndPoint(ofPoint p){
        bezierPoint[1] = p;
    };
    ofPoint getEndPoint(){
        return bezierPoint[1];
    };
    void setControlPoint(int num, ofPoint p){
        if(0<=num && num<2) bezierPoint[num+2] = p;
    };
    ofPoint getControlPoint(int num){
        if(0<=num && num<2) return bezierPoint[num+2];
    };
    ofPoint* getBezierPoints(){
        return bezierPoint;
    }
    void setBezierPoints(ofPoint* p){
        for(auto i:{0,1,2,3})
            bezierPoint[i] = p[i];
    }
    void setBezierPoint(int i,ofPoint p){
        bezierPoint[i] = p;
    }
};