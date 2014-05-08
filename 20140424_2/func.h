#pragma once

#ifndef __FUNC_H__
#define __FUNC_H__

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
using namespace std;

#include "type.h"

int menu();

typedef Item* ItemPtr;

void Load(ItemPtr& , int&);
void Save(const ItemPtr& , const int&);


void Insert(ItemPtr& , int&);
void Delete(ItemPtr& , int&);
void List(const ItemPtr& , const int&);
void Error();

void ItemCopy(Item&, const Item&);

void SafeDelete(ItemPtr&);

#endif // __FUNC_H__