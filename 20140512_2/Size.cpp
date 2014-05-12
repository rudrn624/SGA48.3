#include "Size.h"

Size::Size(const int& _w/*=0*/, const int& _h/*=0*/)
: _width(_w), _height(_h)
{
}

int& Size::width()
{
	return _width;
}
int& Size::height()
{
	return _height;
}
void Size::width(const int& w)
{
	_width = w;
}
void Size::height(const int& h)
{
	_height = h;
}
std::ostream& operator << (std::ostream& os, const Size& s)
{
	os << "Size(" << s._width << ", " << s._height << ")";

	return os;
}
