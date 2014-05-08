#pragma once

#include "LinkedList.h"
#include <queue>

class Queue
{
	typedef LinkedList::data_type data_type;
	typedef LinkedList::size_type size_type;
public :
	Queue();
	~Queue();

	void push(const data_type& v);
	void pop();
	data_type front() const;
	data_type back() const;
	size_type size() const;
	bool empty() const;
	void print() const;

private :
	LinkedList depot;
};