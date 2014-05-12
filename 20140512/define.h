#pragma once

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include "Point.h"

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

