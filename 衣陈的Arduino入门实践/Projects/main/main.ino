#include <MsTimer2.h>
#include"key.h"
#include"oled.h"
#include"pwd.h"
#include"Timer1.h"

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
void (*Timer1_callback) ();

void setup()
{
  key_setup();
  Oled_setup();
  pwdInit();
  Timer1_setup(33);
  Timer1_callback=&keyscan;
  Serial.begin(115200);
  Timer1on();
}
void loop()
{
 
  update();
  OledDraw();
  if(len>=PWDLEN)
  {
    if(Check(pwd,PWD))
    {
       Serial.println("UNFOLD");
    }
    pwdInit();
  }


 Timeroff();
 if(Serial.available())
 {
   static String RX=Serial.readString();
   Serial.print(RX.c_str());
 }
 Timer1on();
 
 static unsigned long it=0;
 unsigned time=millis();
 if(time-it>1000)
 {
    Timeroff();
    for(int i=0;i<4;i++) Serial.print(pwd[i]);
    Serial.println(time);
    it=time;
    Timer1on();
 }
}


