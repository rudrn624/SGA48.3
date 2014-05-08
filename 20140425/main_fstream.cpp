#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

struct gugu
{
	int dan;
	int num;
	int value;
	char multi;
	char equal;
};

int main(void)
{
	fstream file;

	file.open("test.txt", ios_base::in);

	if (!file.good())
	{
		file.close();
	}
	else
	{
		while (file.good())
		{
			gugu buffer;
			file >> buffer.dan >> buffer.multi >> buffer.num;
			file >> buffer.equal >> buffer.value;

			cout << buffer.dan << buffer.multi << buffer.num;
			cout << buffer.equal << buffer.value;

			if (buffer.dan * buffer.num != buffer.value)
				cout << "(x)" << (buffer.dan * buffer.num);
			cout << endl;
		}
	}

	file.close();

	_getch();
	return 0;
}