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
#include "ofxDatGuiTextInputField.h"

class ofxDatGuiTextInput : public ofxDatGuiComponent {

    public:
    
        ofxDatGuiTextInput(string label, string text = "") : ofxDatGuiComponent(label)
        {
            mType = ofxDatGuiType::TEXT_INPUT;
            input = new ofxDatGuiTextInputField(mStyle.height - (mStyle.padding * 2));
            input->setText(text);
            input->onInternalEvent(this, &ofxDatGuiTextInput::onInputChanged);
            onThemeSet(ofxDatGuiComponent::getTheme());
        }
    
        ~ofxDatGuiTextInput()
        {
            delete input;
        }
    
        static ofxDatGuiTextInput* getInstance()
        {
            return new ofxDatGuiTextInput("X");
        }
    
        string getText()
        {
            return input->getText();
        }
    
        void setText(string text)
        {
            return input->setText(text);
        }
    
        void setWidth(int w)
        {
            ofxDatGuiComponent::setWidth(w);
            input->setOrigin(x + mLabel.width, y + mStyle.padding);
            input->setWidth(mStyle.width-mStyle.padding-mLabel.width);
        }
    
        void setOrigin(int x, int y)
        {
            ofxDatGuiComponent::setOrigin(x, y);
            input->setOrigin(x + mLabel.width, y + mStyle.padding);
        }
    
        void draw()
        {
            if (!mVisible) return;
            ofPushStyle();
                ofxDatGuiComponent::drawBkgd();
                ofxDatGuiComponent::drawLabel();
                ofxDatGuiComponent::drawStripe();
                input->draw();
            ofPopStyle();
        }
    
        bool hitTest(ofPoint m)
        {
            return input->hitTest(m);
        }
    
    protected:

        void onFocus()
        {
            input->onFocus();
            ofxDatGuiComponent::onFocus();
        }
    
        void onFocusLost()
        {
            input->onFocusLost();
            ofxDatGuiComponent::onFocusLost();
        }
    
        void onKeyPressed(int key)
        {
            if (key != OF_KEY_UP &&
                key != OF_KEY_DOWN)
            input->onKeyPressed(key);
        }
    
        virtual void onInputChanged(ofxDatGuiInternalEvent e)
        {
        // dispatch event out to main application //
            if (textInputEventCallback != nullptr) {
                ofxDatGuiTextInputEvent ev(this, input->getText());
                textInputEventCallback(ev);
            }   else{
                ofxDatGuiLog::write(ofxDatGuiMsg::EVENT_HANDLER_NULL);
            }
        }
    
        void onThemeSet(const ofxDatGuiTheme* tmplt)
        {
            mStyle.stripe.color = tmplt->stripe.textInput;
            input->setTheme(tmplt);
            setWidth(mStyle.width);
        }
    
        ofxDatGuiTextInputField* input;
    
};

