#pragma once

#include "JuceHeader.h"
class PluginMessage :
    public juce::Message
{
public:
    //Only useful when this is a controller message
    juce::String description;
    
    int index;           //This stores the state of midi message
                        //-1, note on
                        //0, note off
                        //1,11,64 reacts to the controller
    int value;          //when 1,11,64 use this
};

class PluginMessageListener :
    public juce::MessageListener
{
public:
    juce::Slider* selectedSlider1;
    juce::Slider *selectedSlider2;
    juce::Label* selectedLabel;
    int CCNumber;
    int CCValue;
    void handleMessage(const juce::Message&);
};