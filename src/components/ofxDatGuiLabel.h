/*
    Copyright (C) 2015 Stephen Braitsch [http://braitsch.io]

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once
#include "ofxDatGuiComponent.h"

class ofxDatGuiBreak : public ofxDatGuiComponent{

    public:
    
        ofxDatGuiBreak(int height = 0) : ofxDatGuiComponent("break")
        {
            if (height > 0){
                mStyle.height = height;
            }   else {
                mStyle.height = ofxDatGuiComponent::theme->layout.height * .1;
            }
        }
    
        void draw()
        {
            if (!mVisible) return;
            ofPushStyle();
                ofFill();
                ofSetColor(mStyle.color.background, mStyle.opacity);
                ofDrawRectangle(x, y, mStyle.width, mStyle.height);
            ofPopStyle();
        }
    
        int getHeight()
        {
            return mStyle.height;
        }
    
    protected:
    
        void onThemeSet(const ofxDatGuiTheme* tmplt)
        {
            mStyle.height = tmplt->layout.height * .1;
        }
    
};

class ofxDatGuiLabel : public ofxDatGuiComponent{

    public:
        
        ofxDatGuiLabel(string label) : ofxDatGuiComponent(label)
        {
            onThemeSet(ofxDatGuiComponent::getTheme());
        }
    
        void draw()
        {
            ofxDatGuiComponent::drawBkgd();
            ofxDatGuiComponent::drawLabel();
            ofxDatGuiComponent::drawStripe();
        }
    
    protected:
    
        void onThemeSet(const ofxDatGuiTheme* tmplt)
        {
            mStyle.stripe.color = tmplt->stripe.label;
        }


};