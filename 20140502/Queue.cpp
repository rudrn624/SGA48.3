#include "Queue.h"

Queue::Queue()
{
}
Queue::~Queue()
{
}

void Queue::push(const data_type& v)
{
	depot.insert_back(v);
}
void Queue::pop()
{
	depot.remove_front();
}
Queue::data_type Queue::front() const
{
	return depot.begin()->value;
}
Queue::data_type Queue::back() const
{
	return depot.end()->prev->value;
}
Queue::size_type Queue::size() const
{
	return depot.size();
}
bool Queue::empty() const
{
	return depot.empty();
}
void Queue::print() const
{
	depot.print();
}
