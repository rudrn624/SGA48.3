#include "enemy.h"

void TypeC::Update()
{
	_x += dx;
	if (_x > 70)
		dx = -1;
	else if (_x < 0)
		dx = 1;
}
void TypeC::Draw(char* board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if ((_x - 1) <= x && x <= (_x + 1) &&
				(_y - 1) <= y && y <= (_y + 1))
			{
				board[y*70 + x] = '$';
			}
		}
		//cout << endl;
	}
}
