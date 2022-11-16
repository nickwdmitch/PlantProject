/* 
 *  Plant Data Collection with Moisture Sensor and Light Dependen Resistor
 *  Created 06 March 2022 
 *  @author Nick Mitchell
 */ 
#include <Arduino.h>

#include "Sensors.h"
#include "Wifi.h"

// Analog writes pins for each sensor
#define analogSensorPort A0

// Voltage pins for each sensor
#define MoistureSensorEnable D1
#define LDREnable D2

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);

  // Setup pins
  pinMode(A0,INPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
}

void loop() {

  // Variables to hold the values for each sensor
  int moistureSensorValue = 0; 
  int lightDependentResistorValue = 0; 

  // Collect value for both sensors
  SensorSample(MoistureSensorEnable, analogSensorPort, &moistureSensorValue);
  SensorSample(LDREnable, analogSensorPort, &lightDependentResistorValue);

  // Print values to serial monitor
  PrintSensorValues(moistureSensorValue, lightDependentResistorValue); 
  
  // Wait before taking next sample
  delay(100);
}