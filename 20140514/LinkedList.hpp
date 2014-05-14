#pragma once

template<typename T>
struct DoubleNode
{
	typedef T data_type;
	typedef DoubleNode* pointer;

	DoubleNode(const data_type& v, const pointer& p, const pointer& n)
		: value(v), next(n), prev(p)
	{}
	DoubleNode(const pointer& p, const pointer& n)
		: next(n), prev(p)
	{}

	// data
	data_type value;
	// link
	pointer next;
	pointer prev;
};

template<typename T, typename Container>
class Iterator
{
public :
	typedef Iterator<T, Container> Me;
	typedef typename Container::Node Node;
	typedef typename Container::Nodeptr Nodeptr;
	typedef typename Container::data_type data_type;
public :
	Iterator()
		: depot(NULL), data(NULL)
	{}
	Iterator(Container* cont, Nodeptr p)
		: depot(cont), data(p)
	{}

	Me& operator ++ ()
	{
		data = data->next;

		return *this;
	}
	Me operator ++ (int)
	{
		Me tmp(*this);

		++(*this);

		return tmp;
	}
	data_type& operator * ()
	{
		return data->next->value;
	}
	bool operator == (const Me& o)
	{
		return (depot == o.depot && data == o.data);
	}
	bool operator != (const Me& o)
	{
		return (depot != o.depot || data != o.data);
	}

private :
	Container* depot;
	Nodeptr data;
};

template<typename T>
class LinkedList
{
public :
	typedef LinkedList<T> Me;
	typedef DoubleNode<T> Node;
	typedef Node* Nodeptr;
	typedef typename Node::data_type data_type;
	typedef unsigned int size_type;

	typedef Iterator<T, Me> iterator;

public :
	LinkedList()
	{
		init();
	}
	~LinkedList()
	{
		removeall();
	}

	void insert(const data_type& v)
	{
		Node* pNode = new Node(v, current, current->next);

		pNode->next->prev = pNode;
		pNode->prev->next = pNode;

		_size++;
	}
	void remove()
	{
		if (current->next == tail)
			return;

		Node* pNode = current->next;

		pNode->prev->next = pNode->next;
		pNode->next->prev = pNode->prev;

		delete pNode;

		_size--;
	}

	// pageup
	void insert_front(const data_type& v)
	{
		Node* pNode = new Node(v, head, head->next);

		pNode->next->prev = pNode;
		pNode->prev->next = pNode;

		_size++;
	}

	// pagedown
	void insert_back(const data_type& v)
	{
		Node* pNode = new Node(v, tail->prev, tail);

		pNode->next->prev = pNode;
		pNode->prev->next = pNode;

		_size++;
	}
	
	// delete
	void remove_front()
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
	// end
	void remove_back()
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

	void go_front()
	{
		current = head;
	}
	void next()
	{
		if (current->next == tail)
			return;

		current = current->next;
	}
	void prev()
	{
		if (current == head)
			return;

		current = current->prev;
	}

	iterator begin()
	{
		return iterator(this, head);
	}
	iterator end()
	{
		return iterator(this, tail->prev);
	}

	bool empty() const
	{
		return (size() == 0);
	}
	size_type size() const
	{
		return _size;
	}
	data_type value() const
	{
		return current->next->value;
	}

	void print() const
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

private :
	void init()
	{
		tail = new Node(NULL, NULL);
		head = new Node(NULL, tail);
		tail->prev = head;
		current = head;
		_size = 0;
	}
	void removeall()
	{
		while (head)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}

	Nodeptr head;
	Nodeptr tail;
	Nodeptr current;
	size_type _size;
};