#include"oled.h"
#include"pwd.h"
#include<pins_arduino.h>
//oled Part

//main.cpp调用接口
void OledDraw() {
  u8g2.clearBuffer();                   // clear the internal memory
  stateDraw();
  uiDraw();
  pwdDraw();
  u8g2.sendBuffer();                   // transfer internal memory to the display         
}
//密码框与输入指示绘图
void uiDraw()
{
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0,1.3*px,"Password:");
  u8g2.drawFrame(1.5*px  ,1.5*px+2  ,Width-3*px  ,Height-2*px-4 );
  u8g2.drawFrame(1.5*px-1,1.5*px+2-1,Width-3*px+2,Height-2*px-4+2); 
 
}
//模拟的电量，wifi,信号（并不存在）和蓝牙状态绘图），基于setfont设置符号字集
void stateDraw()
{
  u8g2.setFont(u8g2_font_waffle_t_all);   // choose a suitable font
  u8g2.drawGlyph(Width-1*px,px,0xe253);    //电量
  u8g2.drawGlyph(Width-2*px,px,0xe21a);//wifi
  u8g2.drawGlyph(Width-3*px,px,0xe0f0);  //信号
  u8g2.drawGlyph(Width-4*px,px,0xe1b5);  //蓝牙
}
//绘制输入密码
void pwdDraw()
{
  
  u8g2.setFont(u8g2_font_luIS14_tf);
  u8g2.drawStr(3.5*px,1.5*px-1+Height-2*px-4-0.5*px,pwd);
  
}

void Oled_setup() {
  u8g2.begin();
}
