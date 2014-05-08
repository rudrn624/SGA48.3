#include "define.h"

int main(void)
{
	const int width = 70;
	const int height = 20;
	char board[height*width];

	for (int i = 0; i < width*height; i++)
	{
		board[i] = ' ';
	}

	Circle one;
	Rectangle two;
	int x = width/2;
	int y = height/2;
	int dx = 1;
	int dy = 1;

	while (true)
	{
		// update
		x += dx;
		if (x > width)
			dx = -1;
		else if (x < 0)
			dx = 1;
		y += dy;
		if (y > height)
			dy = -1;
		else if (y < 0)
			dy = 1;

		one.SetCenter(x, height/2);
		one.SetRadius(15);
		two.SetCenter(width/2, y);
		two.SetSize(15,15);

		// draw
		// board 에 그리기
		for (int i = 0; i < width*height; i++)
		{
			board[i] = ' ';
		}
		one.Draw(board);
		two.Draw(board);

		// board의 내용을 화면에 출력.
		system("cls");
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				cout << board[y*width + x];
			}
			cout << endl;
		}
	}

	_getch();
	return 0;
}