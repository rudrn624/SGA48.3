#include <iostream>
#include <conio.h>

using namespace std;

// function overloading..
void MySwap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
//// 오버로드된 함수가 'void MySwap(int &,int &)'과(와) 반환 형식만 다릅니다.
//int MySwap(int& a, int& b)
//{
//	int c = a;
//	a = b;
//	b = c;
//	return a;
//}
//// error C2668: 'MySwap' : 오버로드된 함수에 대한 호출이 모호합니다.
//void MySwap(int a, int b)
//{
//	int c = a;
//	a = b;
//	b = c;
//}
void MySwap(float& a, float& b)
{
	float c = a;
	a = b;
	b = c;
}
void MySwap(double& a, double& b)
{
	double c = a;
	a = b;
	b = c;
}

int main(void)
{
	int a = 3;
	int b = 2;

	cout << a << ", " << b << endl;
	MySwap(a, b);
	cout << a << ", " << b << endl;

	float c = 3.1f;
	float d = 3.15f;

	cout << c << ", " << d << endl;
	MySwap(c, d);
	cout << c << ", " << d << endl;

	_getch();
	return 0;
}
