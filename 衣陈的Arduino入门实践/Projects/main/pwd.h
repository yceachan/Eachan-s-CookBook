#include<Arduino.h>
extern char pwd[7];
extern char PWD[7];
#define PWDLEN 4
bool Check(char* lhs,char* rhs);
void update();
void pwdInit();
extern int len;