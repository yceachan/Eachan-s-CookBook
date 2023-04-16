#include<Arduino.h>
#include<pins_arduino.h>
#include"Timer1.h"
#include"pwd.h"
static unsigned long clk=0;
void Timer1_setup(int hz)
{
  cli();//关闭全局中断
  
  TCCR1A = 0;//TCCR1为控制寄存器,共AB 16位，A资源：COM1A1,COM1A0,COM1B!,COM1B0,-,-,WGM11,WGM10
  TCCR1B = 0;//                           B资源：ICNC1,ICES1,-,WGM13,-,WGM12,CS12,CS11,CS10
  TIMSK1 = 0;

  TCNT1  = 0;  //16位计数器寄存器
  OCR1A = 16000000/hz/256 -1;// 16位比较寄存器,共AB两个 ocr=晶振/(分频*目标频率) -1; 
  
  TCCR1B |= (1 << WGM12);//Timer1下控制寄存器WGM1_位真值：`0100` ，即基于OCR1A的CTC模式
  TCCR1B |= (1 << CS12);//Timer1下控制寄存器   CS1_位真值：`100` ，即256倍分频

 // TIMSK1 |= (1 << OCIE1A);//TIMSK使能寄存器。 8位，资源：-,-,ICIE1,-,-,OCIE1B,OCIE1A,TOIE1，此语句使能OCR1A中断
  
  sei();//恢复全局中断
}
void (*Timer1_callback) ();
ISR(TIMER1_COMPA_vect)
{
  sei();//此行为恢复全局中断，执行该行后此定时中断可以被其他中断打断（串口中断与Timer0）
  //clk+=33;
  //Serial.println("ISRing");
  if(Timer1_callback) (*Timer1_callback)(); 
  // else Serial.println("error");
}
unsigned long T1millis()
{
  return clk;
}

void Timeroff()
{
  TIMSK1 &= ~(1 << OCIE1A);//置0
}
void Timer1on()
{
  TIMSK1 |= (1 << OCIE1A);//置1
}

