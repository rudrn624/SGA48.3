#pragma once

#ifndef __TYPE_H__
#define __TYPE_H__

struct Item
{
	int price;
	char name[20];
};

enum menu_id
{
	EXIT,
	INSERT,
	DELETE,
	LIST,
};
#endif // __TYPE_H__