#pragma once

#include "Point.h"

class Shape
{
public :
	void SetPosition(const Point& pt);
	Point GetPosition() const;
	virtual void Update() = 0;
	virtual void Draw(char* board) = 0;
	virtual Shape& operator >> (char* board);
protected :
	Point pos;
};

class Circle : public Shape
{
public :
	Circle();
	void SetRadius(const int& r);
	void Update();
	void Draw(char *board);
	Shape& operator >> (char* board);

private :
	int _r;
	int dx;
};

class Square : public Shape
{
public :
	Square();
	void SetSize(const int& w, const int& h);
	void Update();
	void Draw(char *board);
	Shape& operator >> (char* board);
private :
	int _width;
	int _height;
	int dy;
};

class Airplane : public Shape
{
public :
	Airplane();
	void SetSize(const int& size);
	void Update();
	void Draw(char* board);
	void Move(const Point& diff);
	Shape& operator >> (char* board);
private :
	int _size;
};

