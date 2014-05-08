#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	// 반복문 (loop)
	//int input;
	//cout << "반복할 횟수를 지정하세요 : ";
	//cin >> input;

	//for (int i = 0; i < input; i++)
	//{
	//	cout << "hello world" << endl;
	//	cout << "good job" << endl;
	//	cout << "==================" << endl;
	//}

	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			cout << j << " x " << i+1 << " = " << (j)*(i+1) << endl;
		}
		cout << "======================" << endl;
	}

	cout << "bye" << endl;
	_getch();
	return 0;
}
