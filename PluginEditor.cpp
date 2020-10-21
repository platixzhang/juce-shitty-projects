/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MocengPlayerAudioProcessorEditor::MocengPlayerAudioProcessorEditor (MocengPlayerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
    keyboardComponent(p.keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 600);


    //UI Settings
    devInfo.setFont(juce::Font(10.0f));
    devInfo.setColour(juce::Label::textColourId, juce::Colours::black);
    devInfo.setJustificationType(juce::Justification::centredLeft);
    devInfo.setText("Developed by Platix Zhang", juce::NotificationType::dontSendNotification);
    addAndMakeVisible(&devInfo);

    //Debug Settings
    keyPressed.setFont(juce::Font(30.0f));
    keyPressed.setColour(juce::Label::textColourId, juce::Colours::black);
    keyPressed.setJustificationType(juce::Justification::centred);
    keyPressed.setText("No Key Pressed", juce::NotificationType::dontSendNotification);
    addAndMakeVisible(&keyPressed);

    //Sliders Settings
    CC1.setSliderStyle(juce::Slider::Rotary);
    CC1.setRange(0.0, 127.0, 1.0);
    CC1.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    CC1.setPopupDisplayEnabled(true, false, this);
    CC1.setTextValueSuffix(" Dynamics");
    addAndMakeVisible(&CC1);

    CC11.setSliderStyle(juce::Slider::Rotary);
    CC11.setRange(0.0, 127.0, 1.0);
    CC11.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    CC11.setPopupDisplayEnabled(true, false, this);
    CC11.setTextValueSuffix(" Expressions");
    addAndMakeVisible(&CC11);

    CC1t.setText("Dynamics\nCC1", juce::dontSendNotification);
    CC1t.setFont(juce::Font(25.0f));
    CC1t.setColour(juce::Label::textColourId, juce::Colours::black);
    CC1t.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&CC1t);

    CC11t.setText("Expression\nCC11", juce::dontSendNotification);
    CC11t.setFont(juce::Font(25.0f));
    CC11t.setColour(juce::Label::textColourId, juce::Colours::black);
    CC11t.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&CC11t);

    keyboardComponent.setAvailableRange(21, 108);
    keyboardComponent.setKeyWidth(15.0f);
    addAndMakeVisible(keyboardComponent);



    MocengPlayerAudioProcessor* MCProcessor = (MocengPlayerAudioProcessor*)&audioProcessor;
    MCProcessor->getPML().selectedLabel = &keyPressed;

    //Set Sliders
    MCProcessor->getPML().selectedSlider1 = &CC1;
    MCProcessor->getPML().selectedSlider2 = &CC11;

}

MocengPlayerAudioProcessorEditor::~MocengPlayerAudioProcessorEditor()
{
    MocengPlayerAudioProcessor* MCProcessor = (MocengPlayerAudioProcessor*)&audioProcessor;
    MCProcessor->getPML().selectedLabel = NULL;
    MCProcessor->getPML().selectedSlider1 = NULL;
    MCProcessor->getPML().selectedSlider2 = NULL;
}

//==============================================================================
void MocengPlayerAudioProcessorEditor::paint (juce::Graphics& g)
{
    MocengPlayerAudioProcessor* MCProcessor = (MocengPlayerAudioProcessor*)&audioProcessor;
    MCProcessor->getPML().selectedLabel = &keyPressed;
    MCProcessor->getPML().selectedSlider1 = &CC1;
    MCProcessor->getPML().selectedSlider2 = &CC11;
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::white);

}

void MocengPlayerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    //UI SetBounds
    devInfo.setBounds(0, 0, 800, 20);
    keyPressed.setBounds(0, 20, 800, 180);

    CC1.setBounds(0, 200, 200, 100);
    CC11.setBounds(0, 350, 200, 100);
    CC1t.setBounds(0, 150, 200, 50);
    CC11t.setBounds(0, 300, 200, 50);

    keyboardComponent.setBounds(10, 500, 800, 85);

}
