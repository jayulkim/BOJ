#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char map[15][15];

char point[15][15];

int result[15][15];

typedef struct pos
{
	int x;
	int y;
}pos;
pos list[300];

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s", map[i]);
	}
	for (int i = 0; i < num1; i++)
	{
		scanf("%s", point[i]);
	}

	int index = 0;
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num1; j++)
		{
			if (map[i][j] == '*')
			{
				list[index].x = i;
				list[index].y = j;
				index++;
			}
		}
	}
	int num2 = 0;
	for (int i = 0; i < num1; i++)
	{
		

		for (int j = 0; j < num1; j++)
		{
			int countstar = 0;
			if (point[i][j] == 'x')
			{
				if (i - 1 >= 0)
				{
					if (map[i - 1][j] == '*')
					{
						countstar++;
					}
					if (j - 1 >= 0)
					{
						if (map[i - 1][j - 1] == '*')
						{
							countstar++;
						}
					}
					if (j + 1 < num1)
					{
						if (map[i - 1][j + 1] == '*')
						{
							countstar++;
						}
					}
				}
				if (i + 1 < num1)
				{
					if (map[i + 1][j] == '*')
					{
						countstar++;
					}
					if (j - 1 >= 0)
					{
						if (map[i + 1][j - 1] == '*')
						{
							countstar++;
						}
					}
					if (j + 1 < num1)
					{
						if (map[i + 1][j + 1] == '*')
						{
							countstar++;
						}
					}
				}
				if (j - 1 >= 0)
				{
					if (map[i][j - 1] == '*')
					{
						countstar++;
					}
				}
				if (j + 1 < num1)
				{
					if (map[i][j + 1] == '*')
					{
						countstar++;
					}
				}

				if (map[i][j] == '*')
				{
					num2++;
				}
				else
				{
					result[i][j] = countstar;
					countstar = 0;
				}
				
				
			}
			else if (point[i][j] == '.')
			{
				result[i][j] = -1;
			}
		}
	}
	if (num2 != 0)
	{
		for (int i = 0; i < index; i++)
		{
			result[list[i].x][list[i].y] = -2;
		}

		for (int i = 0; i < num1; i++)
		{
			for (int j = 0; j < num1; j++)
			{
				if (result[i][j] == -1)
				{
					printf(".");
				}
				else if (result[i][j] == -2)
				{
					printf("*");
				}
				else
				{
					printf("%d", result[i][j]);
				}
			}
			printf("\n");
		}
	}
	else
	{
		for (int i = 0; i < num1; i++)
		{
			for (int j = 0; j < num1; j++)
			{
				if (result[i][j] == -1)
				{
					printf(".");
				}
				else
				{
					printf("%d", result[i][j]);
				}
			}
			printf("\n");
		}
	}
	

}
