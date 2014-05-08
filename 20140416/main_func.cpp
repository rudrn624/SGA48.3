#include <iostream>
#include <conio.h>

using namespace std;

int main(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
	{
		cout << i << "번째 인자 : ";
		cout << argv[i] << endl;
	}

	_getch();
	return 0;
}