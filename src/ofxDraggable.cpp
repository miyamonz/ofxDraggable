
#include "ofxDraggable.h"


ofxDraggable::ofxDraggable(int num) {
    pointNum = num;
    
    dragPoint.resize(num, ofPoint(0,0,0));
    lineColor.resize(num,ofColor::white);
    innerColor.resize(num);;
    radius.resize(num,50);
    key.resize(num);
    isSelected.resize(num, false);
    isShow.resize(num,true);
    isEnableKey.resize(num,false);
    isEnableMouse.resize(num, true);
    
    for(int i=0; i<num; i++) {
        dragPoint[i] = ofPoint(10+i*50, 10);
    }
    
    //event
    ofRegisterMouseEvents(this);
    ofRegisterKeyEvents(this);
    ofAddListener(ofEvents().draw, this, &ofxDraggable::draw);
    
}
int ofxDraggable::getPointNum(){
    return pointNum;
}

void ofxDraggable::draw(ofEventArgs & drawArgs) {
    ofPushStyle();
    ofSetCircleResolution(40);
    for(int i=0; i<pointNum; i++) {
        if(!isShow[i]) continue;
        
        //line
        ofSetLineWidth(0.5);
        ofFill();
        ofSetColor(innerColor[i]);
        ofDrawCircle(dragPoint[i], radius[i]);
        //inner
        if(isSelected[i]) ofSetLineWidth(4);
        ofNoFill();
        ofSetColor(lineColor[i]);
        ofDrawCircle(dragPoint[i], radius[i]);
        
        ofDrawBitmapStringHighlight(ofToString((char)key[i]), dragPoint[i]);
    }
    ofPopStyle();
}

void ofxDraggable::mousePressed(ofMouseEventArgs & mouse) {
    for(int i=0; i<pointNum; i++){
        if (mouse.distance(dragPoint[i]) < radius[i] and isEnableMouse[i] and isSelected[i]) {
            isSelected[i] = true;
        }
    }
}
void ofxDraggable::mouseMoved(ofMouseEventArgs & mouse) {
}
void ofxDraggable::mouseDragged(ofMouseEventArgs &mouse) {
    for(int i=0; i<pointNum; i++) if(isSelected[i]) setPosition(i,mouse);
}
void ofxDraggable::mouseReleased(ofMouseEventArgs & mouse) {
    for(int i=0; i<pointNum; i++) {
        //isSelected[i] = false;
    }
}
void ofxDraggable::mouseScrolled(ofMouseEventArgs &mouse){
}
void ofxDraggable::mouseEntered(ofMouseEventArgs &mouse) {
}
void ofxDraggable::mouseExited(ofMouseEventArgs &mouse){
}
void ofxDraggable::keyPressed(ofKeyEventArgs& keyArgs) {
    for(int i=0; i<pointNum; i++) if(keyArgs.key == key[i] && isEnableKey[i]) {
        isSelected[i] = !isSelected[i];
    }//isSelected[i] = true;
}
void ofxDraggable::keyReleased(ofKeyEventArgs &keyArgs){
    for(int i=0; i<pointNum; i++) if(keyArgs.key == key[i] && isEnableKey[i]) {
        
    }
    //isSelected[i] = false;
}

//point
void ofxDraggable::setPosition(int i, ofPoint p) {
    dragPoint[i] = p;
}
void ofxDraggable::setPositions(vector<ofPoint> p){
    if(p.size() != pointNum) return;
    
    for(int i=0; i<pointNum; i++){
        dragPoint[i] = p[i];
    }
}
ofPoint ofxDraggable::getPosition(int i) {
    return dragPoint[i];
}
vector<ofPoint> ofxDraggable::getPositions() {
    return dragPoint;
}

//key
void ofxDraggable::setKey(int i, int k){
    key[i] = k;
    //isEnableKey[i] = true;
}

void ofxDraggable::setLineColor(int i, ofColor c){
    lineColor[i] = c;
}
void ofxDraggable::setLineColorAll(ofColor c){
    for(int i=0; i<pointNum; i++) setLineColor(i, c);
}
void ofxDraggable::setInnerColor(int i, ofColor c){
    innerColor[i] = c;
}
void ofxDraggable::setInnerColorAlpha(int i,int a) {
    innerColor[i].a = a;
}
void ofxDraggable::setInnerColorAll(ofColor c) {
    for(int i=0; i<pointNum; i++) setInnerColor(i, c);
}

ofColor ofxDraggable::getInnerColor(int i) {
    return innerColor[i];
}
ofColor ofxDraggable::getLineColor(int i) {
    return lineColor[i];
}


void ofxDraggable::enable(int i) {
    isEnableKey[i] = true;
    isEnableMouse[i] = true;
}
void ofxDraggable::disable(int i) {
    isEnableKey[i] = false;
    isEnableMouse[i] = false;
}

void ofxDraggable::enableKey(int i){
    isEnableKey[i] = true;
}
void ofxDraggable::enableMouse(int i){
    isEnableMouse[i] = true;
}
void ofxDraggable::disableKey(int i){
    isEnableKey[i] = false;
}
void ofxDraggable::disableMouse(int i){
    isEnableMouse[i] = false;
}
void ofxDraggable::toggleKey(int i){
    isEnableKey[i] = !isEnableKey[i];
}
void ofxDraggable::toggleMouse(int i){
    isEnableMouse[i] = !isEnableMouse[i];
}


void ofxDraggable::enableAll() {
    for(int i=0; i<pointNum; i++) enable(i);
}
void ofxDraggable::disableAll() {
    for(int i=0; i<pointNum; i++) disable(i);
}

void ofxDraggable::show(int i){
    isShow[i] = true;
}
void ofxDraggable::hide(int i) {
    isShow[i] = false;
}
void ofxDraggable::toggleShow(int i) {
    isShow[i] = !isShow[i];
}
void ofxDraggable::showAll() {
    for(int i=0; i<pointNum; i++) show(i);
}
void ofxDraggable::hideAll() {
    for(int i=0; i<pointNum; i++) hide(i);
}
void ofxDraggable ::toggleShowAll() {
    for(int i=0; i<pointNum; i++) toggleShow(i);
}
void ofxDraggable::selectOff(int i) {
    isSelected[i] = false;
}
void ofxDraggable::selectOffAll() {
    for(int i=0; i<pointNum; i++) selectOff(i);
}

