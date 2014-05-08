#include "Stack.h"

Stack::Stack()
{
}
Stack::~Stack()
{
}

void Stack::push(const data_type& v)
{
	depot.insert_front(v);
}
void Stack::pop()
{
	depot.remove_front();
}
Stack::data_type Stack::top() const
{
	return depot.begin()->value;
}
Stack::size_type Stack::size() const
{
	return depot.size();
}
bool Stack::empty() const
{
	return depot.empty();
}
void Stack::print() const
{
	depot.print();
}
