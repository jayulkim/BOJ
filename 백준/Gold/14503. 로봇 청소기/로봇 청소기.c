#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int map[55][55] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	int x0 = 0;
	int y0 = 0;
	int d = 0;
	scanf("%d %d %d", &x0, &y0, &d);

	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	int right = 0;
	int left = 0;
	int up = 0;
	int down = 0;
	map[x0][y0] = -1;
	int x = x0;
	int y = y0;
	int count = 1;
	if (d == 0)
	{
		up = 1;
	}
	else if (d == 1)
	{
		right = 1;
	}
	else if (d == 2)
	{
		down = 1;
	}
	else if (d == 3)
	{
		left = 1;
	}
	while (1)
	{
		if (map[x + 1][y] == 0 || map[x - 1][y] == 0 || map[x][y - 1] == 0 || map[x][y + 1] == 0)
		{
			if (up == 1)
			{
				up = 0;
				left = 1;
			}
			else if (down == 1)
			{
				down = 0;
				right = 1;
			}
			else if (right == 1)
			{
				right = 0;
				up = 1;
			}
			else if (left == 1)
			{
				left = 0;
				down = 1;
			}
			if (up == 1)
			{
				if (map[x-1][y] == 0)
				{
					map[x-1][y] = -1;
					count++;
					x = x - 1;
				}
			}
			else if (down == 1)
			{
				if (map[x+1][y] == 0)
				{
					map[x+1][y] = -1;
					count++;
					x = x + 1;
				}
			}
			else if (right == 1)
			{
				if (map[x][y+1] == 0)
				{
					map[x][y+1] = -1;
					count++;
					y = y + 1;
				}
			}
			else if (left == 1)
			{
				if (map[x][y-1] == 0)
				{
					map[x][y-1] = -1;
					count++;
					y = y - 1;
				}
			}
		}
		else
		{
			if (up == 1)
			{
				if (map[x+1][y] == 1)
				{
					printf("%d", count);
					return 0;
				}
				else
				{
					if (map[x+1][y] == 0)
					{
						map[x+1][y] = -1;
						count++;
					}
					x = x + 1;
				}
			}
			else if (down == 1)
			{
				if (map[x-1][y] == 1)
				{
					printf("%d", count);
					return 0;
				}
				else
				{
					if (map[x-1][y] == 0)
					{
						map[x-1][y] = -1;
						count++;
					}
					x = x - 1;
				}
			}
			else if (right == 1)
			{
				if (map[x][y-1] == 1)
				{
					printf("%d", count);
					return 0;
				}
				else
				{
					if (map[x][y-1] == 0)
					{
						map[x][y-1] = -1;
						count++;
					}
					y = y - 1;
				}
			}
			else if (left == 1)
			{
				if (map[x][y+1] == 1)
				{
					printf("%d", count);
					return 0;
				}
				else
				{
					if (map[x][y+1] == 0)
					{
						map[x][y+1] = -1;
						count++;
					}
					y = y + 1;
				}
			}
		}
	}
}