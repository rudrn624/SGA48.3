#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

// Item 이라는 구조체 타입을 선언.
struct Item
{
	int price;
	char name[20];
};

// 구조체 : structure.
int main(void)
{
	// 구조체 변수 선언..
	Item myItem;

	// 구조체 변수에 값 설정..
	myItem.price = 150;
	strcpy_s(myItem.name, 20, "hello");

	// 구조체 변수의 값을 출력...
	cout << myItem.price << ", " << myItem.name << endl;

	_getch();
	return 0;
}
