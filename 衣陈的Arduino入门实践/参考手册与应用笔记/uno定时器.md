Timer1资源如下：

# 控制寄存器TCCR1~A\B~

![image-20221206221314097](https://s2.loli.net/2022/12/06/7u1aGHb6joCRJBT.png)

![image-20221206221411417](https://s2.loli.net/2022/12/06/Y4RL5JIykzcrQO2.png)

共AB十六位，可配置比较寄存器模式(COM1X\_)，计数模式(WGM1\_),分频系数（CS1\_）,外部中断相关ICxx(不懂)

## 1.COM1_( **Compare Output Mode,**)

比较寄存器模式

![image-20221206221737514](https://s2.loli.net/2022/12/06/Q8qr1Yk3XWBxlen.png)

## 2.WGM1_（**Waveform Generation Mode Bit Description**）

定时/计数模式

![image-20221206221744866](https://s2.loli.net/2022/12/06/fstMnAHTOKmXwCE.png)

## 3.CS1_( **Clock Select Bit Description**)

![image-20221206221802005](https://s2.loli.net/2022/12/06/Ktqgc4H51SeuYpl.png)



# 计数寄存器TCNT1

![image-20221206223226197](https://s2.loli.net/2022/12/06/OhQavDwfd1k9R8M.png)

16为

# 比较寄存器OCR1~A/B~

![image-20221206223404385](https://s2.loli.net/2022/12/06/SwfLuonBa3R5de1.png)

溢出计数模式下，计数频率公式：（晶振）/（分频系数*目标频率）-1

# 使能寄存器TIMSK1

![image-20221206223501743](https://s2.loli.net/2022/12/06/EDYO4hLuvSbgcqr.png)

![image-20221206223530458](https://s2.loli.net/2022/12/06/Sz2KLu7HmdhRVlq.png)

# ISR终端服务函数

~~~C++
ISR(TIMER1_COMPA_vect)//参数为中断编号
{
  cli();
  //Serial.println("ISRing");
  if(callback) (*callback)(); 
 // else Serial.println("error");
  sei();
}
~~~

# Code

~~~C++
#include<Arduino.h>
#include<pins_arduino.h>
#include"Timer1.h"
#include"key.h"
void Timer1_setup(int px)
{
  cli();//关闭全局中断
  
  TCCR1A = 0;//TCCR1为控制寄存器,共AB 16位，A资源：COM1A1,COM1A0,COM1B!,COM1B0,-,-,WGM11,WGM10
  TCCR1B = 0;//                           B资源：ICNC1,ICES1,-,WGM13,-,WGM12,CS12,CS11,CS10
  TIMSK1 = 0;

  TCNT1  = 0;  //16位计数器寄存器
  OCR1A = 16000000/px/256 -1;// 16位比较寄存器,共AB两个 ocr=晶振/(分频*目标频率) -1; 
  
  TCCR1B |= (1 << WGM12);//Timer1下控制寄存器WGM1_位真值：`0100` ，即基于OCR1A的CTC模式
  TCCR1B |= (1 << CS12);//Timer1下控制寄存器   CS1_位真值：`100` ，即256倍分频

  TIMSK1 |= (1 << OCIE1A);//TIMSK使能寄存器。 8位，资源：-,-,ICIE1,-,-,OCIE1B,OCIE1A,TOIE1，此语句使能OCR1A中断
  
  sei();//恢复全局中断
}
void (*callback) ();
ISR(TIMER1_COMPA_vect)
{
  cli();
  //Serial.println("ISRing");
  if(callback) (*callback)(); 
 // else Serial.println("error");
  sei();
}

void Timeroff()
{
  TIMSK1 &= ~(1 << OCIE1A);//置0
}
void Timer1on()
{
  TIMSK1 |= (1 << OCIE1A);//置1
}

~~~

