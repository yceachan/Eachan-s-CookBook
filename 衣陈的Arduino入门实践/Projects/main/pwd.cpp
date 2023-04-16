#include<Arduino.h>
#include<pins_arduino.h>
#include"pwd.h"
#include"key.h"
#include"List.h"
char pwd[7]="____\r\n";
char PWD[7]="0615\r\n";
int len=0;

void update()
{
  if(len>=PWDLEN)
  {
      while(buffer.front()!=buffer.tail) buffer.pop();
      return;
  }
  while(buffer.front()!=buffer.tail && len<PWDLEN)
  {
    
    List::node* buf=buffer.front();
    if(buf==buffer.tail) return;
    for(int i=0;i<N;i++) digitalWrite(col[i],0);
    int r=buf->r,c=buf->c;
    buffer.pop();
    if(digitalRead(row[r])) pwd[len++]=key[r][c]; 
  }
}

//pwdpart
void pwdInit()
{
    for(int i=0;i<PWDLEN;i++) pwd[i]='_';
    len=0;
}
bool Check(char* lhs,char* rhs)
{
 for(int i=0;i<PWDLEN;i++) if(lhs[i]!=rhs[i]) return false;
 return true;
}