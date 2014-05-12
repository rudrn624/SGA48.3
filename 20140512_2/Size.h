#pragma once

#include <iostream>

class Size
{
public :
	Size(const int& _w = 0, const int& _h = 0);

	int& width();
	int& height();
	void width(const int& w);
	void height(const int& h);

	friend std::ostream& operator << (std::ostream& os, const Size& s);

private :
	int _width;
	int _height;
};