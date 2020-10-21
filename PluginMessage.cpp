#include "PluginMessage.h"

void PluginMessageListener::handleMessage(const juce::Message& message)
{
	PluginMessage* inMessage = (PluginMessage*)&message;
	if (selectedLabel == NULL || selectedSlider1 == NULL || selectedSlider2 == NULL) return;
	selectedLabel->setText(inMessage->description, juce::NotificationType::dontSendNotification);
	if (inMessage->index == 1 || inMessage->index == 11)
	{
		//This is a controller event
		//CCNumber = inMessage->index;
		CCValue = inMessage->value;
		if(inMessage->index == 1)
		selectedSlider1->setValue(inMessage->value,juce::NotificationType::dontSendNotification);
		if(inMessage->index == 11)
		selectedSlider2->setValue(inMessage->value,juce::NotificationType::dontSendNotification);
	}
	if (inMessage->index == 0 || inMessage->index == -1)
	{
		//This is a note on or off event
		//Wait for next procedure
	}
}