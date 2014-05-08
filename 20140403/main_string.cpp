#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int main(void)
{
	char buffer[20] = {"hello "};

	// strlen : ���ڿ��� ���̸� ���ϴ� �Լ�.
	cout << "strlen(buffer) : ";
	cout << strlen(buffer) << endl;

	// strcmp : string compare, ���ڿ��� ���ϴ� �Լ�.
	// ������ 0
	// ���� ���ڰ� ũ�� 1
	// ���� ���ڰ� ũ�� -1
	cout << strcmp(buffer, "hello ") << endl;
	if (strcmp(buffer, "hello ") == 0)
	{
		cout << "�� ���ڿ��� �����մϴ�." << endl;
	}

	// warning C4996: 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
	// strcpy : string copy, ���ڿ��� �����ϴ� �Լ�.
	cout << buffer << endl;
	cout << "strcpy(buffer, \"world\") : ";
	cout << strcpy_s(buffer, 20, "world") << endl;
	cout << buffer << endl;

	// strcat : string concatnate, ���ڿ��� ������ �� ����ϴ� �Լ�.
	cout << buffer << endl;
	strcat_s(buffer, 20, " welcome");
	cout << buffer << endl;

	strcpy_s(buffer, "hello");
	// strrev : string reverse, ���ڿ��� ������ �Ųٷ� ������ �Լ�.
	cout << buffer << endl;
	strrev(buffer);
	cout << buffer << endl;

	_getch();
	return 0;
}
