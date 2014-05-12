#include "enemy.h"

void TypeB::Update()
{
	pos += Point(dx, 0);
	if (pos.getx() > 70)
		dx = -1;
	else if (pos.getx() < 0)
		dx = 1;
}
void TypeB::Draw(char* board)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2*i + 1; j++)
		{
			int p = (pos.gety() + i - 3/2)*70 + pos.getx() + j - (2*i + 1)/2;
			if (p >= 70*20)
				continue;
			else
				board[p] = '$';
		}
	}
	int p = (pos.gety() + 2 - 3/2)*70 + pos.getx() + 2 - (2*2 + 1)/2;
	if (p < 70*20)
		board[p] = '$';
}
Enemy& TypeB::operator >> (char* board)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2*i + 1; j++)
		{
			int p = (pos.gety() + i - 3/2)*70 + pos.getx() + j - (2*i + 1)/2;
			if (p >= 70*20)
				continue;
			else
				board[p] = '$';
		}
	}
	int p = (pos.gety() + 2 - 3/2)*70 + pos.getx() + 2 - (2*2 + 1)/2;
	if (p < 70*20)
		board[p] = '$';

	return *this;
}
