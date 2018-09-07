#include "ofApp.h"

ofShader createShaderFromText(string shaderText) {
    ofShader returnShader;
    returnShader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderText);
    returnShader.bindDefaults();
    returnShader.linkProgram();
    return returnShader;
}

string createShaderText(char *templatedShaderText, double newValue) {
    char buffer [1000];
    // Need to figure out how to capture values & pass them around later ...
    // probably should use fmt: https://github.com/fmtlib/fmt
    snprintf( buffer, 1000, templatedShaderText, newValue);
    return buffer;
}

//--------------------------------------------------------------
void ofApp::setup(){
    // Below demonstrates the stringstream approach, but it requires converting
    // to a string using .str() though & it's annoying to add a trailing \
    // so I went with placing strings next to each other, for now!
//     stringstream fragmentSrc;
//     fragmentSrc << "\n\
//  #ifdef GL_ES\n\
//  precision highp float;\n\
//  #endif\n\
//  uniform float u_time;\
//  uniform vec2 u_resolution;\
//  void main() { \
//      // Normalized pixel coordinates (from 0 to 1)\
//      vec2 uv = gl_FragCoord.xy/u_resolution.xy;\
//      // Time varying pixel color\
//      vec3 col = 0.5 + %f*cos(u_time+uv.xyx+vec3(0,2,4));\
//      gl_FragColor = vec4(col,1.0);\
//  }";
    fragmentSrc =
        " #ifdef GL_ES\n"
        " precision highp float;\n"
        " #endif\n"
        " uniform float u_time;"
        " uniform vec2 u_resolution;"
        " void main() { "
            // Normalized pixel coordinates (from 0 to 1)
            "vec2 uv = gl_FragCoord.xy/u_resolution.xy;"
            // Time varying pixel color
            "vec3 col = 0.5 + %f*cos(u_time+uv.xyx+vec3(0,2,4));"
            // "vec3 col = 0.5 + 0.5*cos(u_time*%f+uv.xyx+vec3(0,2,4));"
            "gl_FragColor = vec4(col,1.0);"
        " }";
    shader = createShaderFromText(createShaderText(fragmentSrc, defaultShaderTestValue));

    windowWidth = ofGetWidth();
    windowHeight = ofGetHeight();
}

void ofApp::draw(){
    int sampleHeight = windowHeight * 0.24;
    // ofSetColor(255);
    // shader.begin();
    // shader.setUniform1f("u_time", ofGetElapsedTimef());
    // shader.setUniform2f("u_resolution", windowWidth, windowHeight);
    // ofDrawRectangle(0, 0, windowWidth, sampleHeight);
    // shader.end();

    // Here, draw a loop going from 1 to n creating new shaders but setting the same uniforms!!!!! Just copy the current shader lines, can abstract later if you need to do this more than twice!!
    for (int i = 1; i < 5; ++i) {
        double changedValue = defaultShaderTestValue * (1.0/i);
        ofLog() << i << " : " << changedValue;
        string newShaderText = createShaderText(fragmentSrc, changedValue);
        ofShader newShader = createShaderFromText(newShaderText);
        ofSetColor(255);
        newShader.begin();
        newShader.setUniform1f("u_time", ofGetElapsedTimef());
        newShader.setUniform2f("u_resolution", windowWidth, windowHeight);
        ofDrawRectangle(0, sampleHeight * i - sampleHeight, windowWidth, sampleHeight);
        newShader.end();
    }
    ofLog() << " ----- done ----- ";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    windowWidth = ofGetWidth();
    windowHeight = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
