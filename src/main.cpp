#include <Arduino.h>
String TemparatureRun(double temp)
{
  if(temp < 10) return "Cold!"; 
  if(temp > 10 && temp < 15) return "Cool!"; 
  if(temp > 15 && temp < 25) return "Perfect!"; 
  if(temp > 25 && temp < 30) return "Warm"; 
  if(temp > 30 && temp < 35) return "Hot"; 
   return "Too hot!";
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n A/D Converter!");
}

void loop() {
long read = analogRead(A0);
double temp = mapfloat(read, 0, 1023, 50 ,1);
Serial.println("Digitized Output of " + String(read) + " is Equivalent to a temperature of " + temp + " deg " + TemparatureRun(temp) ); 
delay(500); 
}