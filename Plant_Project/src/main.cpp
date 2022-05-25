/* 
 *  Plant Data Collection with Moisture and Light Sensors
 *  Created 06 March 2022 
 *  modified 25 May 2022 
 *  @author Nick Mitchell
 */ 
#include <Arduino.h>

#define MoistureSensorPin D5
#define LightDependentResistorPin D6

/* Set Initial Values */
float MoistureSensorValue = 0;
float LightDependentResistorValue = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {

  //Take the average of 100 measured values for both sensors
  for (int i = 0; i <= 100; i++) 
  { 
    MoistureSensorValue = MoistureSensorValue + analogRead(MoistureSensorPin); 
    LightDependentResistorValue = LightDependentResistorValue + analogRead(LightDependentResistorPin); 
    delay(1); 
  } 
  MoistureSensorValue = MoistureSensorValue/100.0; 
  LightDependentResistorValue = LightDependentResistorValue/100.0;

  //Print average of measured values
  Serial.print("Moisture Value: "); 
  Serial.println(MoistureSensorValue); 
  Serial.print("Light Value: ");
  Serial.println(LightDependentResistorValue); 
  delay(1000); //Take sample every minute

}