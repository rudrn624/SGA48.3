#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	int menu;

	cout << "0. 종료" << endl;
	cout << "1. 게임시작" << endl;
	cout << "2. 불러오기" << endl;
	cout << "3. 저장하기" << endl;

	cout << "메뉴를 선택하세요 : ";
	cin >> menu;

	if (menu == 0)
	{
		cout << "종료합니다." << endl;
	}
	else if (menu == 1)
	{
		cout << "게임을 시작하지...." << endl;
	}
	else if (menu == 2)
	{
		cout << "저장된 게임을 불러옵니다..." << endl;
	}
	else if (menu == 3)
	{
		cout << "게임을 저장합니다..." << endl;
	}
	else
	{
		cout << "잘못된 메뉴를 선택하셨습니다." << endl;
	}


	switch (menu)
	{
	case 0 :
		{
			cout << "종료합니다." << endl;
		}
		break;
	case 1 :
		{
			cout << "게임을 시작하지...." << endl;
		}
		break;
	case 2 :
		{
			cout << "저장된 게임을 불러옵니다..." << endl;
		}
		break;
	case 3 :
		{
			cout << "게임을 저장합니다..." << endl;
		}
		break;
	default :
		{
			cout << "잘못된 메뉴를 선택하셨습니다." << endl;
		}
		break;
	}



	//switch (a)
	//{
	//case 0 :
	//case 1 :
	//case 2 :
	//case 3 :
	//case 4 :
	//case 5 :
	//	{
	//		cout << "유레카" << endl;
	//	}
	//	break;
	//}

	//if (a%3 == 0)
	//{
	//	cout << "3n" << endl;
	//}
	//if (a%3 == 1)
	//{
	//	cout << "3n + 1" << endl;
	//}
	//if (a%3 == 2)
	//{
	//	cout << "3n + 2" << endl;
	//}

	cout << "종료하려면 아무키나 누르세요." << endl;
	_getch();
	return 0;
}
