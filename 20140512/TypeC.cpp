#include "enemy.h"

void TypeC::Update()
{
	pos += Point(dx, 0);
	if (pos.getx() > 70)
		dx = -1;
	else if (pos.getx() < 0)
		dx = 1;
}
void TypeC::Draw(char* board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if ((pos.getx() - 1) <= x && x <= (pos.getx() + 1) &&
				(pos.gety() - 1) <= y && y <= (pos.gety() + 1))
			{
				board[y*70 + x] = '$';
			}
		}
		//cout << endl;
	}
}
Enemy& TypeC::operator >> (char* board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if ((pos.getx() - 1) <= x && x <= (pos.getx() + 1) &&
				(pos.gety() - 1) <= y && y <= (pos.gety() + 1))
			{
				board[y*70 + x] = '$';
			}
		}
		//cout << endl;
	}

	return *this;
}
