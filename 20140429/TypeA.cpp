#include "enemy.h"

void TypeA::Update()
{
	_x += dx;
	if (_x > 70)
		dx = -1;
	else if (_x < 0)
		dx = 1;
}
void TypeA::Draw(char* board)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2*(2-i) + 1; j++)
		{
			int pos = (_y + i - 3/2)*70 + _x + j - (2*(2-i) + 1)/2;
			if (pos >= 70*20)
				continue;
			else
				board[pos] = '$';
		}
	}
}
