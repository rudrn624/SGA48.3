#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	int menu;

	cout << "0. ����" << endl;
	cout << "1. ���ӽ���" << endl;
	cout << "2. �ҷ�����" << endl;
	cout << "3. �����ϱ�" << endl;

	cout << "�޴��� �����ϼ��� : ";
	cin >> menu;

	if (menu == 0)
	{
		cout << "�����մϴ�." << endl;
	}
	else if (menu == 1)
	{
		cout << "������ ��������...." << endl;
	}
	else if (menu == 2)
	{
		cout << "����� ������ �ҷ��ɴϴ�..." << endl;
	}
	else if (menu == 3)
	{
		cout << "������ �����մϴ�..." << endl;
	}
	else
	{
		cout << "�߸��� �޴��� �����ϼ̽��ϴ�." << endl;
	}


	switch (menu)
	{
	case 0 :
		{
			cout << "�����մϴ�." << endl;
		}
		break;
	case 1 :
		{
			cout << "������ ��������...." << endl;
		}
		break;
	case 2 :
		{
			cout << "����� ������ �ҷ��ɴϴ�..." << endl;
		}
		break;
	case 3 :
		{
			cout << "������ �����մϴ�..." << endl;
		}
		break;
	default :
		{
			cout << "�߸��� �޴��� �����ϼ̽��ϴ�." << endl;
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
	//		cout << "����ī" << endl;
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

	cout << "�����Ϸ��� �ƹ�Ű�� ��������." << endl;
	_getch();
	return 0;
}
