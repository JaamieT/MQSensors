#include "MQ3.h"

MQ3::MQ3(){}

MQ3::MQ3(uint8_t aPin, uint8_t dPin){
	analogPin = aPin;
	digitalPin = dPin;
	currentValue = 0;
}

float MQ3::takeReading(){
	currentValue = analogRead(analogPin);
	return currentValue;
}

void MQ3::setAnalogPin(uint8_t aPin){
	analogPin = aPin;
}

void MQ3::setDigitalPin(uint8_t dPin){
	digitalPin = dPin;
}

float MQ3::getCurrentValue(){
	return currentValue;
}

uint8_t  MQ3::getAnalogPin(){
	return analogPin;
}

uint8_t  MQ3::getDigitalPin(){
	return digitalPin;
}