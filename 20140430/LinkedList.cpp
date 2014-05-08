#include "LinkedList.h"

/////////////////////////////////////////////
// SingleNode
/////////////////////////////////////////////
SingleNode::SingleNode(const data_type& v, const pointer& n)
: value(v), next(n)
{
}
SingleNode::SingleNode(const pointer& n)
: next(n)
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
	Node* pNode = new Node(v, current->next);

	current->next = pNode;

	_size++;
}
void LinkedList::remove()
{
	if (current->next == tail)
		return;

	Node* pNode = current->next;

	current->next = pNode->next;

	delete pNode;

	_size--;
}

void LinkedList::insert_front(const data_type& v)
{
	Node* pNode = new Node(v, head->next);

	head->next = pNode;

	_size++;
}
void LinkedList::insert_back(const data_type& v)
{
	Node* pNode = new Node(v, tail);

	Node* pTemp = head;
	while (pTemp->next != tail)
		pTemp = pTemp->next;

	pTemp->next = pNode;

	_size++;
}

void LinkedList::remove_front()
{
	if (head->next == tail)
		return;

	Node* pNode = head->next;

	head->next = pNode->next;

	if (current == pNode)
	{
		current = head;
	}

	delete pNode;

	_size--;
}
void LinkedList::remove_back()
{
	if (head->next == tail)
		return;

	Node* pNode = head;

	while (pNode->next->next != tail)
		pNode = pNode->next;

	Node* pDelete = pNode->next;

	pNode->next = tail;

	if (current == pDelete)
	{
		current = pNode;
	}

	delete pDelete;

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

	Nodeptr pNode = current;

	current = head;
	while (current->next != pNode)
		current = current->next;
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
		cout << "[" << pNode->value << "]";
		cout << pNode << "--->" << pNode->next;
		cout << endl;

		pNode = pNode->next;
	}
}

void LinkedList::init()
{
	tail = new Node(NULL);
	head = new Node(tail);
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

