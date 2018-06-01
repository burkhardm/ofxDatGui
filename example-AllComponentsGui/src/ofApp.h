#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

#include <cstdint>
#include <vector>

class ofApp : public ofBaseApp{

	public:
        void setup();
        void draw();
        void update();
    
        ofxDatGui* gui;
        bool mFullscreen;
        void refreshWindow();
        void toggleFullscreen();

        void keyPressed(int key);
        void onButtonEvent(ofxDatGuiButtonEvent e);
        void onToggleEvent(ofxDatGuiToggleEvent e);
        void onSliderEvent(ofxDatGuiSliderEvent e);
        void onTextInputEvent(ofxDatGuiTextInputEvent e);
        void on2dPadEvent(ofxDatGui2dPadEvent e);
        void onDropdownEvent(ofxDatGuiDropdownEvent e);
        void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
        void onMatrixEvent(ofxDatGuiMatrixEvent e);
    
        std::uint32_t tIndex;
        std::vector<ofxDatGuiTheme*> themes;

};
