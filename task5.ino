#include <Wire.h>
#include<EEPROM.h>
#include <RTClib.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
RTC_DS1307 RTC;
int Hor,Min,Sec;
char* mySubject[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int i=0,pos=4,j=0;
void setup()
{
Wire.begin();
RTC.begin();
lcd.begin(16,2);
lcd.setCursor(4,0);
lcd.print("School");
lcd.setCursor(0,1);
lcd.print("  Alarm Clock  ");
 delay(2000);
 lcd.clear();
    
 if(!RTC.isrunning())
 {
 RTC.adjust(DateTime(_DATE,__TIME_));
 }
}

void loop() {
Default();
  


}



void Default(){
 DateTime now = RTC.now();
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Time:");
 lcd.setCursor(6,0);
 Hor=now.hour(),DEC;
 lcd.print(Hor=now.hour(),DEC);
 lcd.print(":");
 Min=now.minute(),DEC;
 lcd.print(Min=now.minute(),DEC); 
 lcd.print(":");
 lcd.print(Sec=now.second(),DEC);
 lcd.setCursor(0,1);
 lcd.print("Date: ");
 lcd.print(now.day(),DEC);
 lcd.print("/");
 lcd.print(now.month(),DEC);
 lcd.print("/");
 lcd.print(now.year(),DEC);
 delay(200);
}  
