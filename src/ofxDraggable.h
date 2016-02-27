#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"

class ofxDraggable{
private:
    int pointNum;
    ofPoint dragPoint;
    ofColor lineColor;
    ofColor innerColor;
    float   radius;
    int     key;
    bool    isSelected;
    bool    isShow;
    bool    isEnableKey;
    bool    isEnableMouse;
public:
    
    
    ofxDraggable();
    
    void setup();
    
    int getPointNum();
    
    virtual void draw(ofEventArgs & drawArgs);
    
    void mousePressed(ofMouseEventArgs & mouse);
    void mouseMoved(ofMouseEventArgs & mouse);
    void mouseReleased(ofMouseEventArgs & mouse);
    void mouseDragged(ofMouseEventArgs & mouse);
    void mouseScrolled(ofMouseEventArgs & mouse);
    void mouseEntered(ofMouseEventArgs & mouse);
    void mouseExited(ofMouseEventArgs & mouse);
    
    void keyPressed(ofKeyEventArgs& keyArgs);
    void keyReleased(ofKeyEventArgs& keyArgs);
    
    void setPosition(int i, ofPoint p);
    void setPositions(vector<ofPoint> p);
    ofPoint getPosition(int i);
    
    void setKey(int i, int k);
    
    void setLineColor(int i, ofColor c);
    void setLineColorAll(ofColor c);
    void setInnerColor(int i, ofColor c);
    void setInnerColorAlpha(int i,int a);
    void setInnerColorAll(ofColor c);
    ofColor getInnerColor(int i);
    ofColor getLineColor(int i);
    
    void enable(int k);
    void disable(int k);
    void enableKey(int k);
    void enableMouse(int k);
    void disableKey(int k);
    void disableMouse(int k);
    void toggleKey(int k);
    void toggleMouse(int k);
    void enableAll();
    void disableAll();
    
    void show(int i);
    void hide(int i);
    void toggleShow(int i);
    void showAll();
    void hideAll();
    void toggleShowAll();
    
    void selectOff(int i);
    void selectOffAll();
   
};
