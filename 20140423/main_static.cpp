#include <iostream>
#include <conio.h>

using namespace std;

class Test
{
	enum 
	{
		count = 12,
	};
public :
	Test(const int& i = count)
		: a(i) // initializer
	{
	}
	void print()
	{
		for (int i = 0; i < a; i++)
		{
			cout << 2 << " x " << i+1 << " = " << 2*(i+1) << endl;
		}
	}
private :
	const int a;
	int board[count];
};

int main(void)
{
	//int input;
	//cin >> input;

	Test any;

	any.print();

	_getch();
	return 0;
}
