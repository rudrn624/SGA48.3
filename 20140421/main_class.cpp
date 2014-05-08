#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

class Character
{
public :
	enum type_id
	{
		HUMAN,
		NPC,
		MOB,
	};
public :
	void setType(const int& t)
	{
		type = t;
	}
	int getType()
	{
		return type;
	}
	void setName(const char* _name)
	{
		strcpy_s(name, 20, _name);
	}
	char* getName()
	{
		return name;
	}

private :
	int type;
	char name[20];
};

struct Item
{
	int price;
};

int main(void)
{
	Character Human;

	Human.setType(Character::HUMAN);
	Human.setName("jklim");

	cout << Human.getType() << ", " << Human.getName() << endl;

	_getch();
	return 0;
}