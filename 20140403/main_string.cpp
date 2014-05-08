#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int main(void)
{
	char buffer[20] = {"hello "};

	// strlen : 문자열의 길이를 구하는 함수.
	cout << "strlen(buffer) : ";
	cout << strlen(buffer) << endl;

	// strcmp : string compare, 문자열을 비교하는 함수.
	// 같으면 0
	// 앞의 문자가 크면 1
	// 뒤의 문자가 크면 -1
	cout << strcmp(buffer, "hello ") << endl;
	if (strcmp(buffer, "hello ") == 0)
	{
		cout << "두 문자열은 동일합니다." << endl;
	}

	// warning C4996: 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
	// strcpy : string copy, 문자열을 복사하는 함수.
	cout << buffer << endl;
	cout << "strcpy(buffer, \"world\") : ";
	cout << strcpy_s(buffer, 20, "world") << endl;
	cout << buffer << endl;

	// strcat : string concatnate, 문자열을 연결할 때 사용하는 함수.
	cout << buffer << endl;
	strcat_s(buffer, 20, " welcome");
	cout << buffer << endl;

	strcpy_s(buffer, "hello");
	// strrev : string reverse, 문자열의 내용을 거꾸로 뒤집는 함수.
	cout << buffer << endl;
	strrev(buffer);
	cout << buffer << endl;

	_getch();
	return 0;
}
