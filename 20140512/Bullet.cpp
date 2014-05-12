#include "Bullet.h"

Bullet::Bullet()
{
}
void Bullet::Update(void)
{
	pos -= Point(0, 1);
	if (pos.gety() < 0)
	{
		// todo...
	}
}
void Bullet::Draw(char* board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if (x == pos.getx() && y == pos.gety())
				board[x + y*70] = '^';
		}
	}
}
Shape& Bullet::operator >> (char* board)
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			if (x == pos.getx() && y == pos.gety())
				board[x + y*70] = '^';
		}
	}
	return *this;
}
