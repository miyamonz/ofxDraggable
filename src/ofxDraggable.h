#pragma once
#include <functional>

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxDatGui.h"


class ofxDraggable{
private:
    ofPoint dragPoint;
    ofColor lineColor;
    ofColor innerColor;
    
public:
    //int index;
    float   radius;
    int     key;
    bool    isSelected;
    bool    isPressed;
    bool    isShow;
    bool    isEnableKey;
    bool    isEnableMouse;
    
    
    ofxDraggable();
    
    void setup();
    
    virtual void draw(ofEventArgs & drawArgs);
    void drawLight(ofPoint p ,ofColor c);
    void drawLight(ofPoint p);
    
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
    
    virtual void show(bool);
    void show();
    void hide();
    void toggleShow();
    
    void select(bool );
};
