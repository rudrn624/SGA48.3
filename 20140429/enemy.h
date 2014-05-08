#pragma once

#include "define.h"

class Enemy : public Shape
{
public :
	Enemy();
	virtual void SetCenter(const int& x, const int& y);
	virtual void Update();
	virtual void Draw(char* board);

protected :
	int _x;
	int _y;
	int dx;
};

class TypeA : public Enemy
{
public :
	//void SetCenter(const int& x, const int& y);
	void Update();
	void Draw(char* board);
};

class TypeB : public Enemy
{
public :
	//void SetCenter(const int& x, const int& y);
	void Update();
	void Draw(char* board);
};

class TypeC : public Enemy
{
public :
	//void SetCenter(const int& x, const int& y);
	void Update();
	void Draw(char* board);
};