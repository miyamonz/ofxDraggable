#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"

class ofxDraggable{
private:
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
    
    void setPosition(ofPoint p);
    ofPoint getPosition();
    
    void setKey(int k);
    
    void setLineColor(ofColor c);
    void setInnerColor(ofColor c);
    void setInnerColorAlpha(int a);
    ofColor getInnerColor();
    ofColor getLineColor();
    
    void enable();
    void disable();
    void enableKey();
    void enableMouse();
    void disableKey();
    void disableMouse();
    void toggleKey();
    void toggleMouse();
    
    void show(bool);
    void show();
    void hide();
    void toggleShow();
    
    void select(bool );
   
};
