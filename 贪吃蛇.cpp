#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

#define High 30
#define Wideth 30

int all[High][Wideth] = { 0 };
int move_direction;
int food_x, food_y;

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };
	SetConsoleCursorPosition(handle, pos);
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
//
void start()
{
	int i, j;
	for (i = 0; i < High; i++)
	{
		all[i][0] = -1;
		all[i][Wideth - 1] = -1;
	}
	for (j = 0; j < Wideth; j++)
	{
		all[0][j] = -1;
		all[High - 1][j] = -1;
	}
	all[High / 2][Wideth / 2] = 1;

	for (i = 1; i <= 4; i++)
	{
		all[High / 2][Wideth/2 - i] = i + 1;
	}
	move_direction = 3;
	
	food_x = rand() % (High - 5) + 3;
	food_y = rand() % (Wideth - 5) + 3;
	all[food_x][food_y] = -2;
}
//
void show()
{
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i < High; i++)
	{
		for (j = 0; j < Wideth; j++)
		{
			if (all[i][j] == -1)
				printf("#");
			else if (all[i][j] == 1)
				printf("@");
			else if (all[i][j] == 0)
				printf(" ");
			else if (all[i][j] > 1)
				printf("*");
			else if (all[i][j] == -2)
				printf("F");
		}
		printf("\n");
	}
	Sleep(500);
}
//
void movedirection()
{
	int i, j;
	for (i = 0; i < High; i++)
	{
		for (j = 0; j < Wideth; j++)
		{
			if (all[i][j] > 0)
				all[i][j]++;
		}
	}
	int old_end_i, old_end_j, old_head_i, old_head_j;
	int max = 0;
	for (i = 0; i < High; i++)
	{
		for (j = 0; j < Wideth; j++)
		{
			if (all[i][j] > 0)
			{
				if (max < all[i][j])
				{
					max = all[i][j];
					old_end_i = i;
					old_end_j = j;
				}
				if (all[i][j] == 2)
				{
					old_head_i = i;
					old_head_j = j;
				}
			}
		}
	}
	int new_head_i, new_head_j;

	if (move_direction == 1)
	{
		new_head_i = old_head_i;
		new_head_j = old_head_j - 1;
	}
	if (move_direction == 5)
	{
		new_head_i = old_head_i - 1;
		new_head_j = old_head_j;
	}
	if (move_direction == 3)
	{
		new_head_i = old_head_i;
		new_head_j = old_head_j + 1;
	}
	if (move_direction == 2)
	{
		new_head_i = old_head_i + 1;
		new_head_j = old_head_j;
	}
	if (all[new_head_i][new_head_j] == -2)
	{
		all[food_x][food_y] = 0;
		food_x = rand() % (High - 5) + 1;
		food_y = rand() % (Wideth - 5) + 1;
		all[food_x][food_y] = -2;
	}
	else
		all[old_end_i][old_end_j] = 0;

	if (all[new_head_i][new_head_j] > 0 || all[new_head_i][new_head_j] == -1)
	{
		printf("”Œœ∑Ω· ¯\n");
		Sleep(10000);
		exit(0);
	}
	else
		all[new_head_i][new_head_j] = 1;
}
//
void withoutinput()
{
	movedirection();
}
//
void withinput()
{
	char input;
	if (_kbhit())
	{
		input = _getch();
		if (input == 'a')
		{
			move_direction = 1;
			movedirection();
		}
		else if (input == 'w')
		{
			move_direction = 5;
			movedirection();
		}
		else if (input == 'd')
		{
			move_direction = 3;
			movedirection();
		}
		else if (input == 's')
		{
			move_direction = 2;
			movedirection();
		}
	}
}
//
int main()
{
	start();
	while (1)
	{
		HideCursor();
		show();
		withoutinput();
		withinput();
	}
	return 0;
}