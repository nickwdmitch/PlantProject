#include "Sensors.h"

int AverageOf100Samples(int pin) {

    int tempValue = 0; 
    
    for (int i = 0; i <= 100; i++) 
    { 
        tempValue = tempValue + analogRead(pin); 
        delay(1); 
    } 
    return tempValue = tempValue/100.0; 
}

void PrintSensorValues(int MoistureSensorValue, int LightDependentResistorValue) {
    Serial.print("Moisture Value: "); 
    Serial.println(MoistureSensorValue); 
    Serial.print("Light Value: ");
    Serial.println(LightDependentResistorValue); 
}