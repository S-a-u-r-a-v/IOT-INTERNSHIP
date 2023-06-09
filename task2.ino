#include <Wire.h>         // adds I2C library 
#include <BH1750.h>       // adds BH1750 library file 
#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
char auth[] = "_YONn2J3C8pxB1iIItsalCkS2diOjW9E";       // You should get Auth Token in the Blynk App.
char ssid[] = "FLAT WIFI";                       // Your WiFi credentials.
char pass[] = "Anand#478";
 
BH1750 lightMeter;
 
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  lightMeter.begin();
 
}
void loop() 
{
  Blynk.run();
  float lux = lightMeter.readLightLevel();
  Serial.print("Light Meter: ");
  Serial.print(lux);
  Serial.println(" lx");
  Blynk.virtualWrite(V2, lux);
  delay(1000);
}