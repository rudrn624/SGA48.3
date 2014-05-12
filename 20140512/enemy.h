#pragma once

#include "Shape.h"

class Enemy : public Shape
{
public :
	Enemy();
	virtual void Update();
	virtual void Draw(char* board);
	virtual Enemy& operator >> (char* board);
protected :
	int dx;
};

class TypeA : public Enemy
{
public :
	void Update();
	void Draw(char* board);
	Enemy& operator >> (char* board);
};

class TypeB : public Enemy
{
public :
	void Update();
	void Draw(char* board);
	Enemy& operator >> (char* board);
};

class TypeC : public Enemy
{
public :
	void Update();
	void Draw(char* board);
	Enemy& operator >> (char* board);
};