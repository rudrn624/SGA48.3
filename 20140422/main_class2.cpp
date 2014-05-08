#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

class Test
{
public :
	Test(const char* str)
	{
		value = NULL;
		value = new char[strlen(str) + 1];
		strcpy_s(value, strlen(str)+1, str);
		//value = str;
	}
	Test(const Test& o)
	{
		// value = o.value;
		value = new char[strlen(o.value) + 1];
		strcpy_s(value, strlen(o.value) + 1, o.value);
	}
	~Test()
	{
		if (value)
		{
			delete [] value;
			value = NULL;
		}
	}
	void print()
	{
		if (value)
		{
			cout << value << endl;
		}
	}
private :
	char* value;
};

Test foo(void)
{
	Test a("hello");
	a.print();

	return a;
}

int main(void)
{
	Test b = foo();

	b.print();

	_getch();
	return 0;
}