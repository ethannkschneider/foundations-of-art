/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 400);
    
    // these define the parameters of our slider object
    mix.setSliderStyle (juce::Slider::LinearBarVertical);
    mix.setRange (0.0, 100.0, 1.0);
    mix.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    mix.setPopupDisplayEnabled (true, true, this);
    mix.setTextValueSuffix (" Wet/Dry");
    mix.setValue(1.0);
 
    // this function adds the slider to the editor
    addAndMakeVisible (&mix);
    
    // add the listener to the slider
    mix.addListener (this);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::peachpuff);

    g.setColour (juce::Colours::darkblue);
    g.setFont (15.0f);
    g.drawFittedText ("Bird Language", getLocalBounds(), juce::Justification::centredTop, 1);
    g.setFont(31.0f);
    g.drawFittedText("Foundations of ART", 0, 30, getWidth(), 30, juce::Justification::centred, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    // sets the position and size of the slider with arguments (x, y, width, height)
    mix.setBounds (40, 30, 20, getHeight() - 60);
}

void NewProjectAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    audioProcessor.wetDry = mix.getValue();
}
