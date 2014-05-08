#include <iostream>
#include <conio.h>

using namespace std;

struct UserInfo
{
	int level;
	char name[20];
	int x;
	int y;
};

// pointer : 동적 할당
int main(void)
{
	// 초기화
	UserInfo* pUserInfo = NULL;

	cout << "pUserInfo addr : " << pUserInfo << endl;

	int count = 0;
	cin >> count;

	// 동적 할당
	if (pUserInfo == NULL)
	{
		pUserInfo = new UserInfo[count];
	}

	cout << "pUserInfo addr : " << pUserInfo << endl;

	// 사용...
	for (int i = 0; i < count; i++)
	{
		(pUserInfo+i)->level = 10;
		strcpy_s((pUserInfo+i)->name, 20, "hello");
		(pUserInfo+i)->x = 10;
		(pUserInfo+i)->y = 20;
	}

	// 동적 할당한 메모리를 해제
	if (pUserInfo != NULL)
	{
		delete [] pUserInfo;
		pUserInfo = NULL;
	}

	cout << "pUserInfo addr : " << pUserInfo << endl;


	_getch();
	return 0;
}
