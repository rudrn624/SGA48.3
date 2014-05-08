#include <iostream>
#include <conio.h>

using namespace std;

// 전처리기 (pre-processor)
/*
#include
#define
*/

inline int MyMax(int a, int b)
{
	if (a > b)
		return a;
	else 
		return b;
}

#define MYMAX(a, b) (((a)>(b))? (a):(b))

#define TESTMODE

#ifdef TESTMODE
#define STAGE 2
#elif RANKMODE
#define STAGE 1
#else
#define STAGE 0
#endif

int main(void)
{
	int a = 3;

	MyMax(a, a++);


	_getch();
	return 0;
}
