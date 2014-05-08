#pragma once

#include "define.h"

class Bullet
{
public :
	Bullet();
	void SetPosition(const int& _x, const int& _y);
	void Update(void);
	void Draw(char* board);
	void GetPosition(int& x, int& y);

private :
	int _x;
	int _y;
};