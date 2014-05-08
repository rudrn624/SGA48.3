#include <iostream>
#include <conio.h>

using namespace std;

class Base
{
public :
	void setMoney(const int& m)
	{
		money = m;
	}
	int getMoney() const
	{
		return money;
	}
private :
protected :
	int money;
};

class Derived : private Base
{
public :
	void printMoney()
	{
		cout << money << endl;
	}

};

// 'Base::getMoney' : 'this' 포인터를 'const Base'에서 'Base &'(으)로 변환할 수 없습니다.
void foo(const Base& obj)
{
	cout << obj.getMoney() << endl;
}

int main(void)
{
	Base a;

	a.setMoney(10);

	foo(a);

	_getch();
	return 0;
}
