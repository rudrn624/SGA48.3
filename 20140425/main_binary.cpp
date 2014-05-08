#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

struct Item
{
	int price;
	char name[15];
};

int main(void)
{
	fstream file;

	file.open("binary.aaa", ios_base::out | ios_base::binary);

	//file << "hello" << 123131321231 << endl;

	//char* buffer = "hello";
	//int num = 1231321231;

	//file.write((const char*)buffer, (strlen(buffer)+1)*sizeof(char));
	//file.write((const char*)&num, sizeof(int));

	Item myItem = {150,"pant"};

	// myItem의 주소에 있는 내용을
	// sizeof(Item) 크기만큼 파일에 쓴다.
	file.write((const char*)&myItem, sizeof(Item));

	file.close();

	file.open("binary.aaa", ios_base::in | ios_base::binary);

	Item buffer;

	file.read((char*)&buffer, sizeof(Item));

	cout << buffer.name << endl;
	cout << buffer.price << endl;

	file.close();

	_getch();
	return 0;
}