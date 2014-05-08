#include "define.h"

void zero()
{
	HANDLE hCon = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD z = {0,0};
	::SetConsoleCursorPosition(hCon, z);
}