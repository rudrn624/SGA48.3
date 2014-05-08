#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{	
	char buffer[] = {"hello"};

	// strlen...
	int len = 0;
	for (int i = 0; buffer[i] != '\0'; i++)
	{
		len++;
	}
	cout << buffer << "\'s length : " << len << endl;

	// strcmp
	char tmp[] = {"helloa"};
	int index = 0;

	while (tmp[index] == buffer[index])
	{
		if (tmp[index] == '\0')
		{
			cout << 0 << endl;
			break;
		}
		index++;
	}
	if (tmp[index] > buffer[index])
		cout << 1 << endl;
	else if (tmp[index] < buffer[index])
		cout << -1 << endl;


	// strrev
	// strcat
	// strcpy


	_getch();
	return 0;
}
