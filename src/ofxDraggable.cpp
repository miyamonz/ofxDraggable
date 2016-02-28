
#include "ofxDraggable.h"


ofxDraggable::ofxDraggable() {
    
    dragPoint = ofPoint(10, 10);
    radius = 40;
    isSelected = false;
    //event
    ofRegisterMouseEvents(this);
    ofRegisterKeyEvents(this);

    ofAddListener(ofEvents().draw, this, &ofxDraggable::draw);
    
}

void ofxDraggable::draw(ofEventArgs & drawArgs) {
    if(!isShow) return;

    ofPushStyle();
    ofSetCircleResolution(40);
    //line
    ofSetLineWidth(0.5);
    ofFill();
    ofSetColor(innerColor);
    ofDrawCircle(dragPoint, radius);
    //inner
    if(isSelected) ofSetLineWidth(4);
    ofNoFill();
    ofSetColor(lineColor);
    
    ofDrawCircle(dragPoint, radius);
    ofDrawBitmapStringHighlight(ofToString((char)key), dragPoint);
    ofPopStyle();
}

void ofxDraggable::mousePressed(ofMouseEventArgs & mouse) {
    if (mouse.distance(dragPoint) < radius and isEnableMouse and isSelected) {
        isSelected = true;
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
        isSelected = !isSelected;
    }//isSelected = true;
}
void ofxDraggable::keyReleased(ofKeyEventArgs &keyArgs){
    if(keyArgs.key == key && isEnableKey) {
        
    }
    //isSelected = false;
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


void ofxDraggable::show(bool b) {
    isShow = b;
}
void ofxDraggable::show(){
    isShow = true;
}
void ofxDraggable::hide() {
    isShow = false;
}
void ofxDraggable::toggleShow() {
    isShow = !isShow;
}
void ofxDraggable::select(bool b) {
    isSelected = b;
}
void ofxDraggable::addTags(ofxXmlSettings &xml){
    xml.addTag("x");
    xml.addTag("y");
    xml.addTag("z");
}
//xml
void ofxDraggable::varToXml(ofxXmlSettings &xml){
    xml.setValue("x", dragPoint.x);
    xml.setValue("y", dragPoint.y);
    xml.setValue("z", dragPoint.z);
}

void ofxDraggable::xmlToVar(ofxXmlSettings &xml) {
    dragPoint.x = xml.getValue("x",0);
    dragPoint.y = xml.getValue("y",0);
    dragPoint.z = xml.getValue("z",0);
    
}

