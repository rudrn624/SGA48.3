#include "define.h"

Airplane::Airplane()
: _x(0), _y(0), _size(0)
{
}
void Airplane::SetSize(const int& size)
{
	_size = size;
}
void Airplane::SetCenter(const int& x, const int& y)
{
	_x = x;
	_y = y;
}
void Airplane::Update()
{
}
void Airplane::Draw(char* board)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < 2*i + 1; j++)
		{
			int pos = (_y + i - _size/2)*70 + _x + j - (2*i + 1)/2;
			if (pos >= 70*20)
				continue;
			else
				board[pos] = '*';
		}
	}
}
void Airplane::Move(const int& dx, const int& dy)
{
	_x = _x + dx;
	_y = _y + dy;
}
void Airplane::GetPosition(int& x, int& y)
{
	x = _x;
	y = _y;
}

