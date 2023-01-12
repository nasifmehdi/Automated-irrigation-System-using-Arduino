#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 void setup()
 {


//lcd.init();
 lcd.setCursor(10,0);
 lcd.print("Temperature:");
 }

 void loop()
 {
 float temperatureC = getTemperatureC();
 // now convert to Fahrenheit
 float temperatureF = convertToF(temperatureC);

 lcd.setCursor(21,1);
 lcd.print(temperatureC);
 lcd.print(" C");
   lcd.setCursor(21,2);
 lcd.print(temperatureF);
 lcd.print(" F");
 delay(100);
 }

 float getTemperatureC()
 {
 int reading = analogRead(A0);

float voltage = (reading * 5.0) / 1024;
 // convert from 10 mv per degree with 500mV offset
 // to degrees ((voltage - 500mV) * 100)
 return (voltage - 0.5) * 100;
 }

 float convertToF(float temperatureC)
 {
 return (temperatureC * 9.0 / 5.0) + 32.0;
 }
