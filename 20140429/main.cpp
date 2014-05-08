#include "define.h"
#include "enemy.h"
#include "Bullet.h"
#include "LinkedList.h"

int main(void)
{
	//while (true)
	//{
	//	int key = _getch();
	//	cout << hex << key << endl;
	//}

	//return 0;

	const int width = 70;
	const int height = 20;
	char board[height*width];

	for (int i = 0; i < width*height; i++)
	{
		board[i] = ' ';
	}

	LinkedList bulletDepot;

	//Circle one;
	//Square two;
	Triangle three;

	Shape* some[3] = {&three};//, &two, &three};

	TypeA a;
	TypeB b;
	TypeC c;

	Enemy* enemies[3] = {&a,&b,&c};

	a.SetCenter(5, 5);
	b.SetCenter(15, 7);
	c.SetCenter(50, 5);


	int x = width/2;
	int y = height/2;
	int dx = 1;
	int dy = 1;
	//one.SetRadius(5);
	//one.SetCenter(x, y);
	//two.SetSize(15,15);
	//two.SetCenter(x, y);
	three.SetCenter(x,18);
	three.SetSize(3);

	while (true)
	{
		// input
		if (_kbhit())
		{
			int key = _getch();
			if (key == SPECIAL)
			{
				key = _getch();
				if (key == LEFT)
				{
					three.Move(-1, 0);
				}
				else if (key == RIGHT)
				{
					three.Move(1, 0);
				}
				else if (key == UP)
				{
					three.Move(0, -1);
				}
				else if (key == DOWN)
				{
					three.Move(0, 1);
				}
			}
			else if (key == SPACE)
			{
				Bullet* pBullet = NULL;
				pBullet = new Bullet;
				int x, y;
				three.GetPosition(x, y);
				pBullet->SetPosition(x, y);

				bulletDepot.insert(pBullet);
			}
		} // if (_kbhit())

		// update
		for (int i = 0; i < 3; i++)
		{
			if (some[i])
				some[i]->Update();
		}
		for (int i = 0; i < 3; i++)
		{
			if (enemies[i])
				enemies[i]->Update();
		}
		LinkedList::Node* it;
		for (bulletDepot.go_front(), it = bulletDepot.begin(); it != bulletDepot.end();)
		{
			bulletDepot.value()->Update();

			int x, y;
			bulletDepot.value()->GetPosition(x, y);
			if (y < 0)
			{
				bulletDepot.remove();
			}
			else
			{
				bulletDepot.next();
				it = it->next;
			}
		}
		//one.Update();
		//two.Update();

		// draw
		// board 에 그리기
		for (int i = 0; i < width*height; i++)
		{
			board[i] = ' ';
		}
		for (int i = 0; i < 3; i++)
		{
			if (some[i])
				some[i]->Draw(board);
		}

		for (int i = 0; i < 3; i++)
		{
			if (enemies[i])
				enemies[i]->Draw(board);
		}
		for (bulletDepot.go_front(), it = bulletDepot.begin(); it != bulletDepot.end();
			bulletDepot.next(), it = it->next)
		{
			bulletDepot.value()->Draw(board);
		}
		//one.Draw(board);
		//two.Draw(board);

		// board의 내용을 화면에 출력.
		zero();
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				cout << board[y*width + x];
			}
			cout << endl;
		}
		cout << "current bullet count : ";
		cout << bulletDepot.size() << endl;
	}

	_getch();
	return 0;
}