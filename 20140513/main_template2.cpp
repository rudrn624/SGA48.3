#include <iostream>
#include <conio.h>

using namespace std;

int sum(const int& n)
{
	if (n == 1)
		return 1;

	return sum(n-1) + n;
}

template<int N>
struct sumer
{
	enum { value  = sumer<N-1>::value + N};
};

// template specialization. (템플릿 특수화)
template<>
struct sumer<0>
{
	enum { value = 0};
};

template<int N>
struct factorial
{
	enum { value = factorial<N-1>::value * N };
};

template<>
struct factorial<1>
{
	enum { value = 1};
};

int main(void)
{

	cout << sumer<10>::value << endl;

	cout << sum(10) << endl;

	cout << factorial<5>::value << endl;

	_getch();
	return 0;
}