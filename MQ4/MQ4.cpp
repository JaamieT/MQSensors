#include "MQ4.h"

MQ4::MQ4(){}

MQ4::MQ4(uint8_t aPin, uint8_t dPin){
	analogPin = aPin;
	digitalPin = dPin;
	currentValue = 0;
}

float MQ4::takeReading(){
	currentValue = analogRead(analogPin);
	return currentValue;
}

void MQ4::setAnalogPin(uint8_t aPin){
	analogPin = aPin;
}

void MQ4::setDigitalPin(uint8_t dPin){
	digitalPin = dPin;
}

float MQ4::getCurrentValue(){
	return currentValue;
}

uint8_t  MQ4::getAnalogPin(){
	return analogPin;
}

uint8_t  MQ4::getDigitalPin(){
	return digitalPin;
}