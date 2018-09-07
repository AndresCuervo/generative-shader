#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //    shader.load("shadersGL3/shader");
    stringstream vertexSrc;
    vertexSrc << "#version 150\n";
    vertexSrc << "uniform mat4 modelViewProjectionMatrix;\n";
    vertexSrc  << "in vec4 position;\n";
    vertexSrc  << "in vec2 texcoord;\n";
    vertexSrc  << "out vec2 texCoordVarying;\n";
    vertexSrc  << "void main(void){\n";
    vertexSrc  << "\tgl_Position=modelViewProjectionMatrix*position;\n";
    vertexSrc  << "\ttexCoordVarying = texcoord;\n";
    vertexSrc  << "}\n";

    // TODO: try, uhh, just instantiating this as char *text = ""\n"", where \n is an actual linebreak, see:
    // https://stackoverflow.com/a/1135862
    //
    // ALsooooo, try adding holes to this & sprintf filling the holes with different values :))))
    // ---> I guess they could also be uniforms, but that seems cumbersome, and
    // eventually I want to be able to write these out to files & take in
    // unmodified files, so yeah no, not uniforms for that reason, non-intrusive speculative editing!!!

    stringstream fragmentSrc; fragmentSrc << "\n\ #ifdef GL_ES\n\ precision
        highp float;\n\ #endif\n\ uniform float u_time;\n\ uniform vec2
        u_resolution;\n\ void main() { \n\
            // Normalized pixel coordinates (from 0 to 1)\n\
            vec2 uv = gl_FragCoord.xy/u_resolution.xy;\n\
            // Time varying pixel color\n\
            vec3 col = 0.5 + 0.5*cos(u_time+uv.xyx+vec3(0,2,4));\n\
            gl_FragColor = vec4(col,1.0);\n\ }";

        /*
#ifdef GL_ES
precision highp float;
#endif

//--------------------------------- uniforms:
uniform sampler2DRect fontTexture;
uniform vec2 bounds;

uniform float u_time;

uniform int x_motion_on;
uniform int x_motion_perpendicular;
uniform float x_amplitude;
uniform float x_speed;
uniform float x_waviness;

uniform int y_motion_on;
uniform int y_motion_perpendicular;
uniform float y_amplitude;
uniform float y_speed;
uniform float y_waviness;
//---------------------------------

void main() {
    vec2 coord = gl_FragCoord.xy;
    coord.y = bounds.y - coord.y; // flip along y axis for some reason.
    if (x_motion_on != 0) {
      float x_coord = x_motion_perpendicular != 0 ? coord.y : coord.x;
      coord.x += x_amplitude * sin((u_time * -x_speed) + (x_coord * x_waviness));
    }
    if (y_motion_on != 0) {
      float y_coord = y_motion_perpendicular != 0 ? coord.x : coord.y;
      coord.y += y_amplitude * cos((u_time * -y_speed) + (y_coord * y_waviness));
    }

    gl_FragColor = texture2DRect(fontTexture, coord);
}
         * */

    /*
       void mainImage( out vec4 fragColor, in vec2 fragCoord )
       {
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord/iResolution.xy;

    // Time varying pixel color
    vec3 col = 0.5 + 0.5*cos(iTime+uv.xyx+vec3(0,2,4));

    // Output to screen
    fragColor = vec4(col,1.0);
    }
    */

    //    shader.setupShaderFromSource( GL_VERTEX_SHADER, vertexSrc.str() );
    shader.setupShaderFromSource( GL_FRAGMENT_SHADER, fragmentSrc.str() );
    shader.bindDefaults();
    shader.linkProgram();
}

void ofApp::draw(){
    ofSetColor(255);
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
