#include<Arduino.h>
extern String pwd;
extern String PWD;
#define PWDLEN 4
void pwdUpdate();
bool pwdCheck();
void pwdInit();
extern int pwdlen;