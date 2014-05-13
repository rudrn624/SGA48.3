#include <iostream>
#include <conio.h>

using namespace std;

template<typename T1, 
		 typename T2> 
void MySwap(T1& a, T2& b)
{
	T2 c = a;
	a = b;
	b = c;
}


int main(void)
{
	int* pA = NULL;

	if (pA == NULL)
	{
		pA = new int;
	}

	// todo...


	SafeDelete(pA);
	//if (pA)
	//{
	//	delete pA;
	//	pA = NULL;
	//}

	cout 


	_getch();
	return 0;
}