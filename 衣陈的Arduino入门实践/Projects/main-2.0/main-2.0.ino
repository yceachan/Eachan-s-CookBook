#include<Arduino.h>
#include"key.h"
#include"Timer1.h"
#include"key.h"
#include"oled.h"
#include"pwd.h"

void setup()
{
  
  Oled_setup();
  key_setup();
  pwdInit();
  Timer1_setup(33);
  Timer1_callback=&key_scan;
  Serial.begin(9600);
  Timer1on(); 
}
void loop()
{
 pwdUpdate();
 OledDraw();
 if(pwdCheck())
 {
    Serial.print("UNFOLD\0");
   // HC08.print("UNFOLD");
 }
 if(Serial.available())
 {
   String TX=Serial.readString();
   Serial.print(TX.c_str());
 }
 u32 check =T1millis();
 static u32 it=0;
 if(check-it>1000)
 {
   Serial.print(check);
   Serial.println(pwd.c_str());
   it=check;
 }
}