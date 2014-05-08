#include <iostream>
#include <conio.h>

using namespace std;

// Array 배열
int main(void)
{
	char name[20];
	int birth;

	cout << "이름을 입력하세요 : ";
	cin >> name;

	cout << "태어난 년도를 입력하세요 : ";
	cin >> birth;

	cout << name << "씨는 " << (2014-birth+1) << "살이군요." << endl;
	
	for (int i = 0; i < 20; i++)
	{
		cout << i << " : " << name[i] << " : " << hex << int(name[i]) << endl;
	}

	name[5] = '\0';

	cout << name << endl;


	_getch();
	return 0;
}
