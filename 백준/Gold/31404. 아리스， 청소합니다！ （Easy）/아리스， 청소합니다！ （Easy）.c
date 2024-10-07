#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int map[70][70] = { 0, };

char ruleA[70][70] = { 0, };
char ruleB[70][70] = { 0, };
char str[70];

int map1[70][70] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	int num3 = 0;
	int num4 = 0;
	int num5 = 0;
	scanf("%d %d %d", &num3, &num4, &num5);
	for (int i = 0; i < num1; i++)
	{
		scanf("%s", str);
		for (int j = 0; j < num2; j++)
		{
			ruleA[i][j] = str[j];
		}
	}
	for (int i = 0; i < num1; i++)
	{
		scanf("%s", str);
		for (int j = 0; j < num2; j++)
		{
			ruleB[i][j] = str[j];
		}
	}
	int up = 0;
	int down = 0;
	int right = 0;
	int left = 0;
	int dust = 0;
	int count = 0;
	int count1 = 0;
	if (num5 == 0)
	{
		up = 1;
	}
	else if (num5 == 1)
	{
		right = 1;
	}
	else if (num5 == 2)
	{
		down = 1;
	}
	else if (num5 == 3)
	{
		left = 1;
	}

	int y = num3;
	int x = num4;
	int result = 0;
	while (1)
	{
		if (map[y][x] == 0)
		{
			count1 = 0;
			if (up == 1)
			{
				map[y][x] = 1;
			}
			else if (down == 1)
			{
				map[y][x] = 3;
			}
			else if (right == 1)
			{
				map[y][x] = 2;
			}
			else if (left == 1)
			{
				map[y][x] = 4;
			}
			map1[y][x] = count;
			count++;
			dust = 1;
		}
		else
		{
			count1++;
			if (map[y][x] == 1 && up == 1)
			{
				if (count == map1[y][x])
				{
					printf("%d\n", result - count1 + 1);
					return 0;
				}
				else
				{
					map1[y][x] = count;
				}
			}
			else if (map[y][x] == 3 && down == 1)
			{
				if (count == map1[y][x])
				{
					printf("%d\n", result - count1 + 1);
					return 0;
				}
				else
				{
					map1[y][x] = count;
				}
			}
			else if (map[y][x] == 2 && right == 1)
			{
				if (count == map1[y][x])
				{
					printf("%d\n", result - count1 + 1);
					return 0;
				}
				else
				{
					map1[y][x] = count;
				}
			}
			else if (map[y][x] == 4 && left == 1)
			{
				if (count == map1[y][x])
				{
					printf("%d\n", result - count1 + 1);
					return 0;
				}
				else
				{
					map1[y][x] = count;
				}
			}
			if (up == 1)
			{
				map[y][x] = 1;
			}
			else if (down == 1)
			{
				map[y][x] = 3;
			}
			else if (right == 1)
			{
				map[y][x] = 2;
			}
			else if (left == 1)
			{
				map[y][x] = 4;
			}
			dust = 0;
		}
		if (dust == 1)
		{
			if (ruleA[y][x] == '1')
			{
				if (up == 1)
				{
					up = 0;
					right = 1;
				}
				else if (down == 1)
				{
					down = 0;
					left = 1;
				}
				else if (left == 1)
				{
					left = 0;
					up = 1;
				}
				else if (right == 1)
				{
					right = 0;
					down = 1;
				}
			}
			else if (ruleA[y][x] == '2')
			{
				if (up == 1)
				{
					up = 0;
					down = 1;
				}
				else if (down == 1)
				{
					down = 0;
					up = 1;
				}
				else if (right == 1)
				{
					right = 0;
					left = 1;
				}
				else if (left == 1)
				{
					left = 0;
					right = 1;
				}
			}
			else if (ruleA[y][x] == '3')
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
			}
		}
		else if (dust == 0)
		{
			if (ruleB[y][x] == '1')
			{
				if (up == 1)
				{
					up = 0;
					right = 1;
				}
				else if (down == 1)
				{
					down = 0;
					left = 1;
				}
				else if (left == 1)
				{
					left = 0;
					up = 1;
				}
				else if (right == 1)
				{
					right = 0;
					down = 1;
				}
			}
			else if (ruleB[y][x] == '2')
			{
				if (up == 1)
				{
					up = 0;
					down = 1;
				}
				else if (down == 1)
				{
					down = 0;
					up = 1;
				}
				else if (right == 1)
				{
					right = 0;
					left = 1;
				}
				else if (left == 1)
				{
					left = 0;
					right = 1;
				}
			}
			else if (ruleB[y][x] == '3')
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
			}
		}
		if (up == 1)
		{
			y--;
			result++;
			if (y < 0)
			{
				printf("%d\n", result - count1);
				return 0;
			}
		}
		else if (down == 1)
		{
			y++;
			result++;
			if (y >= num1)
			{
				printf("%d\n", result - count1);
				return 0;
			}
		}
		else if (right == 1)
		{
			x++;
			result++;
			if (x >= num2)
			{
				printf("%d\n", result - count1);
				return 0;
			}
		}
		else if (left == 1)
		{
			x--;
			result++;
			if (x < 0)
			{
				printf("%d\n", result - count1);
				return 0;
			}
		}
	}
}