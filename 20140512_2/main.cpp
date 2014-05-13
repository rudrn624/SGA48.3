#include <iostream>
#include <conio.h>
#include "Circle.h"

using namespace std;

int main(void)
{
	const int width = 70;
	const int height = 20;
	const char blank = ' ';
	char board[width*height];

	for (int i = 0; i < width*height; i++)
	{
		board[i] = blank;
	}

	Circle one(Point(width/2,height/2), 5);
	Circle two(Point(width/2,height/2), 5);

	int dx = 1;
	bool xdir = true;
	int dy = 1;
	bool ydir = true;

	int nCountCollide = 0;

	while (true)
	{
		// update
		one.Move(one.GetPosition() + Point(dx, 0));
		two.Move(two.GetPosition() + Point(0, dy));

		if (one.GetPosition().x() >= width)
			xdir = false;
		else if (one.GetPosition().x() <= 0)
			xdir = true;

		if (two.GetPosition().y() >= height)
			ydir = false;
		else if (two.GetPosition().y() <= 0)
			ydir = true;

		if (xdir)
			dx = 1;
		else
			dx = -1;

		if (ydir)
			dy = 1;
		else
			dy = -1;

		// collide check
		if (one.Collide(&two))
		{
			nCountCollide++;
		}

		// draw
		for (int i = 0; i < width*height; i++)
		{
			board[i] = blank;
		}
		one.Draw(board);
		two.Draw(board);

		system("cls");
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				cout << board[x + y*width];
			}
			cout << endl;
		}

		cout << "collide count : ";
		cout << nCountCollide << endl;
	}

	_getch();
	return 0;
}