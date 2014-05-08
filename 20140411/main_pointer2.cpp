#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	// 포인터 용도 : 참조.
	char msg[] = {"hello"};
	//char* const msg;

	cout << msg << endl;
	msg[0] = 'H';
	cout << msg << endl;

	//const char* pMsg = "world";
	//const char* pMsg1 = "good job";
	//const char* pMsg2 = "go to hell";

	const char* pMsg[] = {"world", "good job", "goto hell"};

	for (int i = 0; i < 3; i++)
	{
		cout << pMsg[i] << endl;
	}

	_getch();
	return 0;
}
