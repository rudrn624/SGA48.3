#pragma once

#include "LinkedList.h"

class Stack
{
	typedef LinkedList::data_type data_type;
	typedef LinkedList::size_type size_type;

public :
	Stack();
	~Stack();

	void push(const data_type& v);
	void pop();
	data_type top() const;
	size_type size() const;
	bool empty() const;
	void print() const;

private :
	LinkedList depot;
};