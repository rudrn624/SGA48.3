#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	int x;
	int y;
	int width;
	int height;

	cout << "x : ";
	cin >> x;
	cout << "y : ";
	cin >> y;
	cout << "width : ";
	cin >> width;
	cout << "height : ";
	cin >> height;

	for (int i = 0; i < y; i++)
	{
		cout << endl;
	}

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < x; i++)
		{
			cout << ' ';
		}
		for (int i = 0; i < width; i++)
		{
			cout << '#';
		}
		cout << endl;
	}

	_getch();
	return 0;
}