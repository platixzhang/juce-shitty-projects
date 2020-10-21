/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MocengPlayerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MocengPlayerAudioProcessorEditor (MocengPlayerAudioProcessor&);
    ~MocengPlayerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MocengPlayerAudioProcessor& audioProcessor;

    //UI Components
    juce::Label devInfo;
    juce::Label keyPressed;

    juce::Slider CC1, CC11;
    juce::Label CC1t, CC11t;

    juce::MidiKeyboardComponent keyboardComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MocengPlayerAudioProcessorEditor)
};