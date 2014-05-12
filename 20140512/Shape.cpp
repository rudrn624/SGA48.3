#include "Shape.h"

void Shape::SetPosition(const Point& pt)
{
	pos = pt;
}
Point Shape::GetPosition() const
{
	return pos;
}
Shape& Shape::operator >> (char* board)
{
	return *this;
}
