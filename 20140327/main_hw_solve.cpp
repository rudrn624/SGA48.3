#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	int input;
	cout << "숫자를 입력하세요 : ";
	cin >> input;

	bool A = (input%2 == 0);
	bool B = (input%3 == 0);
	bool C = (input%8 == 0);
	bool D = (input%12 == 0);

	bool E = (A && B && !C && !D);

	cout << ((E)? "맞아요" : "아닌데요.") << endl;

	_getch();
	return 0;
}