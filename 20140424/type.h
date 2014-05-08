#include <iostream>
#include <conio.h>

using namespace std;

void foo(void);
void bar(void);

// no linkage
//int a;

// external linkage
extern int a;

// internal linkage
static int b;

// internal linkage
const int c = 10;

const char* const msg = "hello";
