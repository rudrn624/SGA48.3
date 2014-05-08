#include "Bullet.h"

Bullet::Bullet()
: _x(-1), _y(-1)
{
}
void Bullet::SetPosition(const int& x, const int& y)
{
	_x = x;
	_y = y;
}
void Bullet::Update(void)
{
	_y -= 1;
	if (_y < 0)
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
			if (x == _x && y == _y)
				board[x + y*70] = '^';
		}
	}
}
void Bullet::GetPosition(int& x, int& y)
{
	x = _x;
	y = _y;
}
