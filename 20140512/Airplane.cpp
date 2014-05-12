#include "Shape.h"

Airplane::Airplane()
: _size(0)
{
}
void Airplane::SetSize(const int& size)
{
	_size = size;
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
			int p = (pos.gety() + i - _size/2)*70 + pos.getx() + j - (2*i + 1)/2;
			if (p >= 70*20)
				continue;
			else
				board[p] = '*';
		}
	}
}
void Airplane::Move(const Point& diff)
{
	pos += diff;
}
Shape& Airplane::operator >> (char* board)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < 2*i + 1; j++)
		{
			int p = (pos.gety() + i - _size/2)*70 + pos.getx() + j - (2*i + 1)/2;
			if (p >= 70*20)
				continue;
			else
				board[p] = '*';
		}
	}

	return *this;
}
