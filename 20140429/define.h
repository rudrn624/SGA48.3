#pragma once

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

enum keycode_id
{
	SPECIAL = 0xE0,
	LEFT	= 0x4B,
	RIGHT	= 0x4D,
	UP		= 0x48,
	DOWN	= 0x50,
	SPACE	= 0x20,
};

void zero();

class Shape
{
public :
	virtual void SetCenter(const int& x, const int& y) = 0;
	virtual void Update() = 0;
	virtual void Draw(char* board) = 0;
};

class Circle : public Shape
{
public :
	Circle();
	void SetCenter(const int& x, const int& y);
	void SetRadius(const int& r);
	void Update();
	void Draw(char *board);

private :
	int _x;
	int _y;
	int _r;
	int dx;
};

class Square : public Shape
{
public :
	Square();
	void SetCenter(const int& x, const int& y);
	void SetSize(const int& w, const int& h);
	void Update();
	void Draw(char *board);
private :
	int _x;
	int _y;
	int _width;
	int _height;
	int dy;
};

class Triangle : public Shape
{
public :
	Triangle();
	void SetSize(const int& size);
	void SetCenter(const int& x, const int& y);
	void Update();
	void Draw(char* board);
	void Move(const int& dx, const int& dy);
	void GetPosition(int& x, int& y);
private :
	int _x;
	int _y;
	int _size;
};

