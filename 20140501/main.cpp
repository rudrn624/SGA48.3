#include "LinkedList.h"

enum keycode_id
{
	SPECIAL = 0xE0,
	LEFT	= 0x4B,
	RIGHT	= 0x4D,
	UP		= 0x48,
	DOWN	= 0x50,
	PAGEUP	= 0x49,
	PAGEDOWN= 0x51,
	DELETE	= 0x53,
	END		= 0x4F,
};

int main(void)
{
	LinkedList test;

	bool need_to_draw = true;

	while (true)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key == '+')
			{
				LinkedList::data_type data;
				cout << "Input Data : ";
				cin >> data;
				test.insert(data);
			}
			else if (key == '-')
			{
				test.remove();
			}
			else if (key == SPECIAL)
			{
				key = _getch();
				if (key == UP)
				{
					test.prev();
				}
				else if (key == DOWN)
				{
					test.next();
				}
				else if (key == PAGEUP)
				{
					LinkedList::data_type data;
					cout << "Input Data : ";
					cin >> data;
					test.insert_front(data);
				}
				else if (key == PAGEDOWN)
				{
					LinkedList::data_type data;
					cout << "Input Data : ";
					cin >> data;
					test.insert_back(data);
				}
				else if (key == DELETE)
				{
					test.remove_front();
				}
				else if (key == END)
				{
					test.remove_back();
				}
			}

			need_to_draw = true;
		}

		// draw
		if (need_to_draw)
		{
			system("cls");
			test.print();
			cout << "node count : ";
			cout << test.size();
			cout << endl;

			need_to_draw = false;
		}
	}

	_getch();
	return 0;
}