#include <iostream>
#include <conio.h>

using namespace std;

// Array �迭
int main(void)
{
	char name[20];
	int birth;

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;

	cout << "�¾ �⵵�� �Է��ϼ��� : ";
	cin >> birth;

	cout << name << "���� " << (2014-birth+1) << "���̱���." << endl;
	
	for (int i = 0; i < 20; i++)
	{
		cout << i << " : " << name[i] << " : " << hex << int(name[i]) << endl;
	}

	name[5] = '\0';

	cout << name << endl;


	_getch();
	return 0;
}
