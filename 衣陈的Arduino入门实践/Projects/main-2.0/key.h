#include"List.h"
typedef unsigned char u8;
typedef unsigned long u32;
#define N 4
#define DELAY 15
extern const char key[N][N];

extern const u8 row[N];
extern const u8 col[N];
extern u32        clc[N][N];
extern List buffer;
void key_setup();
void key_scan();