#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void loading(void)
{
	system("cls");
	cout << "loading ...." << endl;
	_getch();
}

void ingame(void)
{
	system("cls");
	cout << "ingame ...." << endl;
	_getch();
}

void ranking(void)
{
	system("cls");
	cout << "ranking ...." << endl;
	_getch();
}

int main(void)
{
	typedef void (*Scene)(void);

	Scene gameScene[] = {&loading, &ingame, &ranking};

	for (int i = 0; i < sizeof(gameScene)/sizeof(Scene); i++)
	{
		(*gameScene[i])();
	}

	_getch();
	return 0;
}