#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{

	int current = 2014;
	int birth;

	cout << "태어난 년도를 입력하세요 : ";
	cin >> birth;
	cout << "당신의 나이는 " << (current - birth + 1) << "입니다." << endl;

	_getch();
	return 0;
}