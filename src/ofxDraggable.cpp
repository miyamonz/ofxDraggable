
#include "ofxDraggable.h"
//#include "innoPocket.h"



ofxDraggable::ofxDraggable() {
    
    dragPoint = ofPoint(10, 10);
    radius = 40;
    isSelected = false;
    isPressed  = false;
    isEnableKey   = false;
    isEnableMouse = false;
    setInnerColor(ofColor::white);
    //event
    ofRegisterMouseEvents(this);
    ofRegisterKeyEvents(this);
    ofAddListener(ofEvents().draw, this, &ofxDraggable::draw);
    
    
}


void ofxDraggable::draw(ofEventArgs & drawArgs) {
    if(!isShow) return;

    drawLight(dragPoint);
    ofDrawBitmapStringHighlight(ofToString((char)key), dragPoint);
    
}
void ofxDraggable::drawLight(ofPoint p, ofColor c){
    ofPushStyle();
    ofSetCircleResolution(40);
    //inner
    ofSetLineWidth(0.5);
    ofFill();
    ofSetColor(c);
    ofDrawCircle(p, radius);
    
    //line
    if(isPressed) ofSetLineWidth(4);
    ofNoFill();
    ofSetColor(lineColor);
    ofDrawCircle(p, radius);
    ofPopStyle();
}
void ofxDraggable::drawLight(ofPoint p) {
    ofColor c = innerColor;
    drawLight(p,c);
}
void ofxDraggable::mousePressed(ofMouseEventArgs & mouse) {
    if (mouse.distance(dragPoint) < radius and isEnableMouse && isPressed) {
        isSelected = isSelected;
    }
}
void ofxDraggable::mouseMoved(ofMouseEventArgs & mouse) {
}
void ofxDraggable::mouseDragged(ofMouseEventArgs &mouse) {
    if(isSelected) setPosition(mouse);
}
void ofxDraggable::mouseReleased(ofMouseEventArgs & mouse) {
    isSelected = false;
}
void ofxDraggable::mouseScrolled(ofMouseEventArgs &mouse){
}
void ofxDraggable::mouseEntered(ofMouseEventArgs &mouse) {
}
void ofxDraggable::mouseExited(ofMouseEventArgs &mouse){
}
void ofxDraggable::keyPressed(ofKeyEventArgs& keyArgs) {
    if(keyArgs.key == key && isEnableKey) {
        isPressed = !isPressed;
//        isPressed = true;
    }
}
void ofxDraggable::keyReleased(ofKeyEventArgs &keyArgs){
    if(keyArgs.key == key && isEnableKey) {
       //isPressed = false;
    }
    
}

//point
void ofxDraggable::setPosition(ofPoint p) {
    dragPoint = p;
}
ofPoint ofxDraggable::getPosition() {
    return dragPoint;
}

//key
void ofxDraggable::setKey(int k){
    key = k;
    //isEnableKey = true;
}

void ofxDraggable::setLineColor(ofColor c){
    lineColor = c;
}
void ofxDraggable::setInnerColor(ofColor c){
    innerColor = c;
}
void ofxDraggable::setInnerColorAlpha(int a) {
    innerColor.a = a;
}

ofColor ofxDraggable::getInnerColor() {
    return innerColor;
}
ofColor ofxDraggable::getLineColor() {
    return lineColor;
}


void ofxDraggable::enable() {
    isEnableKey = true;
    isEnableMouse = true;
}
void ofxDraggable::disable() {
    isEnableKey = false;
    isEnableMouse = false;
}

void ofxDraggable::enableKey(){
    isEnableKey = true;
}
void ofxDraggable::enableMouse(){
    isEnableMouse = true;
}
void ofxDraggable::disableKey(){
    isEnableKey = false;
}
void ofxDraggable::disableMouse(){
    isEnableMouse = false;
}
void ofxDraggable::toggleKey(){
    isEnableKey = !isEnableKey;
}
void ofxDraggable::toggleMouse(){
    isEnableMouse = !isEnableMouse;
}

void ofxDraggable::setPressed(bool b){
    isPressed = b;
}

void ofxDraggable::show(bool b) {
    isShow = b;
}
void ofxDraggable::show(){
    show(true);
}
void ofxDraggable::hide() {
    show(false);
}
void ofxDraggable::toggleShow() {
    if(isShow) hide();
    else show();
}
void ofxDraggable::select(bool b) {
    isSelected = b;
}

