#pragma once

#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

class Circle
{
public :
	Circle();
	void SetCenter(const int& x, const int& y);
	void SetRadius(const int& r);
	void Draw(char *board);

private :
	int _x;
	int _y;
	int _r;
};

class Rectangle
{
public :
	Rectangle();
	void SetCenter(const int& x, const int& y);
	void SetSize(const int& w, const int& h);
	void Draw(char *board);
private :
	int _x;
	int _y;
	int _width;
	int _height;
};