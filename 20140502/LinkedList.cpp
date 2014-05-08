#include "LinkedList.h"

/////////////////////////////////////////////
// DoubleNode
/////////////////////////////////////////////
DoubleNode::DoubleNode(const data_type& v, const pointer& p, const pointer& n)
: value(v), next(n), prev(p)
{
}
DoubleNode::DoubleNode(const pointer& p, const pointer& n)
: next(n), prev(p)
{
}

/////////////////////////////////////////////
// LinkedList
/////////////////////////////////////////////
LinkedList::LinkedList()
{
	init();
}
LinkedList::~LinkedList()
{
	removeall();
}

void LinkedList::insert(const data_type& v)
{
	Node* pNode = new Node(v, current, current->next);

	//current->next->prev = pNode;
	//current->next = pNode;
	pNode->next->prev = pNode;
	pNode->prev->next = pNode;

	_size++;
}
void LinkedList::remove()
{
	if (current->next == tail)
		return;

	Node* pNode = current->next;

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;

	delete pNode;

	_size--;
}

void LinkedList::insert_front(const data_type& v)
{
	Node* pNode = new Node(v, head, head->next);

	pNode->next->prev = pNode;
	pNode->prev->next = pNode;

	_size++;
}
void LinkedList::insert_back(const data_type& v)
{
	Node* pNode = new Node(v, tail->prev, tail);

	pNode->next->prev = pNode;
	pNode->prev->next = pNode;

	_size++;
}

void LinkedList::remove_front()
{
	if (head->next == tail)
		return;

	Node* pNode = head->next;

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;

	if (pNode == current)
	{
		current = current->prev;
	}

	delete pNode;

	_size--;
}
void LinkedList::remove_back()
{
	if (tail->prev == head)
		return;

	Node* pNode = tail->prev;

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;

	if (pNode == current)
	{
		current = current->prev;
	}

	delete pNode;

	_size--;
}

void LinkedList::next()
{
	if (current->next == tail)
		return;

	current = current->next;
}
void LinkedList::prev()
{
	if (current == head)
		return;

	current = current->prev;
}
LinkedList::Node* LinkedList::begin() const
{
	return head->next;
}
LinkedList::Node* LinkedList::end() const
{
	return tail;
}
bool LinkedList::empty() const
{
	return (size() == 0);
}
LinkedList::size_type LinkedList::size() const
{
	return _size;
}
LinkedList::data_type LinkedList::value() const
{
	return current->next->value;
}
void LinkedList::print() const
{
	Nodeptr pNode = head;

	while (pNode)
	{
		if (pNode == current)
			cout << ">>>";
		else
			cout << "   ";
		cout << pNode->prev << "<---";
		cout << "[" << pNode->value << "]";
		cout << pNode << "--->" << pNode->next;
		cout << endl;

		pNode = pNode->next;
	}
}

void LinkedList::init()
{
	tail = new Node(NULL, NULL);
	head = new Node(NULL, tail);
	tail->prev = head;
	current = head;
	_size = 0;
}
void LinkedList::removeall()
{
	while (head)
	{
		current = head;
		head = head->next;
		delete current;
	}
}

