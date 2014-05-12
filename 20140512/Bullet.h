#pragma once

#include "Shape.h"

class Bullet : public Shape
{
public :
	Bullet();
	void Update(void);
	void Draw(char* board);
	Shape& operator >> (char* board);
};