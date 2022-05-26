/* 
 *  Plant Data Collection with Moisture Sensor and Light Dependen Resistor
 *  Created 06 March 2022 
 *  modified 25 May 2022 
 *  @author Nick Mitchell
 */ 
#include <Arduino.h>
#include <Sensors.h>

#define MoistureSensorPin D5
#define LightDependentResistorPin D6

/* Set Initial Values */
float MoistureSensorValue = 0;
float LightDependentResistorValue = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {

  // Collect value for both sensors
  MoistureSensorValue = AverageOf100Samples(MoistureSensorPin);
  LightDependentResistorValue = AverageOf100Samples(LightDependentResistorValue);

  // Print values to serial monitor
  PrintSensorValues(MoistureSensorValue, LightDependentResistorValue);
  
  // Wait for one minute before taking next sample
  delay(100);

}