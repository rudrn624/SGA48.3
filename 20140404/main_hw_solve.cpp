#include <iostream>
#include <conio.h>

using namespace std;

int main(void)
{
	// strcpy
	//char dest[10];
	//char src[] = {"hello"};
	//int index = 0;

	//while (dest[index] = src[index++]);

	// strcat
	//char buffer[20] = {"hello"};
	//char original[] = {" world"};
	//int len = 0;
	//int index = 0;

	//while (buffer[len] != '\0')
	//	len++;

	////while (buffer[len++] = src[index++]);
	//while (src[index] != '\0')
	//{
	//	buffer[len] = src[index];
	//	len++;
	//	index++;
	//}
	//buffer[len] = '\0';

	// strrev
	char buffer[] = {"hello"};
	int len = 0;

	while (buffer[len] != '\0')
		len++;

	len--;

	int index = 0;
	while (index < len)
	{
		char tmp = buffer[index];
		buffer[index] = buffer[len];
		buffer[len] = tmp;

		index++;
		len--;
	}



	_getch();
	return 0;
}
