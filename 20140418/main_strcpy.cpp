#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	char buffer[] = {"hello world"};
	char temp[] = {"good job"};

	int i = 0;
	//while (buffer[i] = temp[i++]);

	for (i = 0; temp[i] != '\0'; i++)
	{
		buffer[i] = temp[i];
	}
	buffer[i] = '\0';

	_getch();
	return 0;
}
