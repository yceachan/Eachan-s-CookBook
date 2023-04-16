#include"pwd.h"
#include"key.h"
#include<Arduino.h>
#include<pins_arduino.h>
#include"Timer1.h"
String pwd="____\0";
String PWD="4396\0";
int pwdlen=0;
void pwdInit()
{
   pwd="____\0";
   pwdlen=0;
}
bool pwdCheck()
{
  if(pwdlen<PWDLEN) return false;
  if(pwd==PWD)
  {
    pwdInit();
    return true;
  }
  else
  {
    pwdInit();
    return false;
  }
}
void pwdUpdate()
{
  if(pwdlen>=PWDLEN)
  {
    buffer.clear();
    return;
  }
  while(!buffer.empty() && pwdlen<PWDLEN)
  {
    List::node* buf=buffer.front();
    if(buf==buffer.tail) return;
    for(int i=0;i<N;i++) digitalWrite(col[i],0);
    int r=buf->r,c=buf->c;
    buffer.pop();
    if(digitalRead(row[r]) && millis()-clc[r][c]>DELAY) pwd[pwdlen++]=key[r][c]; 
  }
}