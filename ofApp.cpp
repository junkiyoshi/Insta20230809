#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	float radius = 135;

	ofSetColor(239, 39, 39, 200);
	ofFill();

	ofBeginShape();
	for (int deg = 0; deg < 360; deg++) {

		auto x = ofNoise(glm::vec3(cos(deg * DEG_TO_RAD) * 2, sin(deg * DEG_TO_RAD) * 2, ofGetFrameNum() * 0.03)) < 0.5 ? -200 : 200;

		ofVertex(x + radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
	}
	ofEndShape(true);

	ofSetColor(239, 39, 39);
	ofNoFill();

	ofBeginShape();
	for (int deg = 0; deg < 360; deg++) {

		auto x = ofNoise(glm::vec3(cos(deg * DEG_TO_RAD) * 2, sin(deg * DEG_TO_RAD) * 2, ofGetFrameNum() * 0.03)) < 0.5 ? -200 : 200;

		ofVertex(x + radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
	}
	ofEndShape(true);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}