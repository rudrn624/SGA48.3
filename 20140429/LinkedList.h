#pragma once

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "Bullet.h"

using namespace std;

struct DoubleNode
{
	typedef Bullet* data_type;
	typedef DoubleNode* pointer;

	DoubleNode(const data_type& v, const pointer& p, const pointer& n);
	DoubleNode(const pointer& p, const pointer& n);

	// data
	data_type value;
	// link
	pointer next;
	pointer prev;
};

class LinkedList
{
public :
	typedef DoubleNode Node;
	typedef Node* Nodeptr;
	typedef Node::data_type data_type;
	typedef unsigned int size_type;

public :
	LinkedList();
	~LinkedList();

	void insert(const data_type& v);
	void remove();

	// pageup
	void insert_front(const data_type& v);
	// pagedown
	void insert_back(const data_type& v);
	
	// delete
	void remove_front();
	// end
	void remove_back();

	void next();
	void prev();

	Node* begin() const;
	Node* end() const;

	bool empty() const;
	size_type size() const;
	data_type value() const;

	void print() const;

private :
	void init();
	void removeall();

	Nodeptr head;
	Nodeptr tail;
	Nodeptr current;
	size_type _size;
};