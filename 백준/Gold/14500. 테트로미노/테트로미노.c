#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int map[505][505] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	int index = 0;
	int max = 0;
	for (int i = 0; i < num1 - 1; i++)
	{
		for (int j = 0; j < num2 - 1; j++)
		{
			if (max < map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1])
			{
				max = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
			}
		}
	}
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2 - 3; j++)
		{
			if (max < map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3])
			{
				max = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
			}
		}
	}
	for (int i = 0; i < num1 - 3; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			if (max < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j])
			{
				max = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
			}
		}
	}
	for (int i = 0; i < num1 - 1; i++)
	{
		for (int j = 0; j < num2 - 2; j++)
		{
			if (max < map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2])
			{
				max = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			}
		}
	}
	for (int i = 0; i < num1 - 1; i++)
	{
		for (int j = 0; j < num2 - 2; j++)
		{
			if (max < map[i][j] + map[i][j+1] + map[i][j + 2] + map[i + 1][j])
			{
				max = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j];
			}
		}
	}
	for (int i = 0; i < num1 - 1; i++)
	{
		for (int j = 0; j < num2 - 2; j++)
		{
			if (max < map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j+2])
			{
				max = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j+2];
			}
		}
	}
	for (int i = 0; i < num1 - 1; i++)
	{
		for (int j = 0; j < num2 - 2; j++)
		{
			if (max < map[i][j+2] + map[i+1][j] + map[i+1][j + 1] + map[i + 1][j+2])
			{
				max = map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			}
		}
	}
	for (int i = 0; i < num1 - 2; i++)
	{
		for (int j = 0; j < num2 - 1; j++)
		{
			if (max < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1])
			{
				max = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
			}
		}
	}
	for (int i = 0; i < num1 - 2; i++)
	{
		for (int j = 0; j < num2 - 1; j++)
		{
			if (max < map[i][j+1] + map[i + 1][j+1] + map[i + 2][j+1] + map[i][j])
			{
				max = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i][j];
			}
		}
	}
	for (int i = 0; i < num1 - 2; i++)
	{
		for (int j = 0; j < num2 - 1; j++)
		{
			if (max < map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i+2][j])
			{
				max = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i+2][j];
			}
		}
	}
	for (int i = 0; i < num1 - 2; i++)
	{
		for (int j = 0; j < num2 - 1; j++)
		{
			if (max < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j+1])
			{
				max = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
			}
		}
	}
	for (int i = 0; i < num1 - 1; i++)
	{
		for (int j = 0; j < num2 - 2; j++)
		{
			if (max < map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i][j + 1])
			{
				max = map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i][j + 1];
			}
		}
	}
	for (int i = 0; i < num1 - 1; i++)
	{
		for (int j = 0; j < num2 - 2; j++)
		{
			if (max < map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i+1][j + 1])
			{
				max = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			}
		}
	}
	for (int i = 0; i < num1 - 2; i++)
	{
		for (int j = 0; j < num2 - 1; j++)
		{
			if (max < map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i + 1][j])
			{
				max = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i + 1][j];
			}
		}
	}
	for (int i = 0; i < num1 - 2; i++)
	{
		for (int j = 0; j < num2 - 1; j++)
		{
			if (max < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j+1])
			{
				max = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
			}
		}
	}
	for (int i = 0; i < num1 - 2; i++)
	{
		for (int j = 0; j < num2 - 1; j++)
		{
			if (max < map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1])
			{
				max = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			}
		}
	}
	for (int i = 0; i < num1 - 2; i++)
	{
		for (int j = 0; j < num2 - 1; j++)
		{
			if (max < map[i][j+1] + map[i + 1][j+1] + map[i + 1][j] + map[i + 2][j])
			{
				max = map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j] + map[i + 2][j];
			}
		}
	}
	for (int i = 0; i < num1 - 1; i++)
	{
		for (int j = 0; j < num2 - 2; j++)
		{
			if (max < map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2])
			{
				max = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
			}
		}
	}
	for (int i = 0; i < num1 - 1; i++)
	{
		for (int j = 0; j < num2 - 2; j++)
		{
			if (max < map[i+1][j] + map[i+1][j + 1] + map[i][j + 1] + map[i][j + 2])
			{
				max = map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i][j + 2];
			}
		}
	}
	printf("%d", max);
}