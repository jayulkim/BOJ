#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char map[101][101][101];
int ary[101][101][101] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	scanf("%d %d %d", &num1, &num2, &num3);

	for (int i = 0; i < num3; i++)
	{
		for (int j = 0; j < num1; j++)
		{
			scanf("%s", map[i][j]);
			for (int k = 0; k < num2; k++)
			{
				ary[i][j][k] = -1;
			}
		}
	}

	for (int i = 0; i < num3; i++)
	{
		for (int j = 0; j < num1; j++)
		{
			for (int k = 0; k < num2; k++)
			{
				if (map[i][j][k] == '.')
				{
					ary[i][j][k]++;


					if (map[i - 1][j][k] == '*' && i - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i - 1][j - 1][k] == '*' && i - 1 >= 0 && j - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i - 1][j][k - 1] == '*' && i - 1 >= 0 && k - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i - 1][j - 1][k - 1] == '*' && i - 1 >= 0 && k - 1 >= 0 && j - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i - 1][j + 1][k] == '*' && i - 1 >= 0 && j + 1 < num1)
					{
						ary[i][j][k]++;
					}
					if (map[i - 1][j][k + 1] == '*' && i - 1 >= 0 && k + 1 < num2)
					{
						ary[i][j][k]++;
					}
					if (map[i - 1][j + 1][k + 1] == '*' && i - 1 >= 0 && j + 1 < num1 && k + 1 < num2)
					{
						ary[i][j][k]++;
					}
					if (map[i - 1][j + 1][k - 1] == '*' && i - 1 >= 0 && j + 1 < num1 && k - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i - 1][j - 1][k + 1] == '*' && i - 1 >= 0 && j - 1 >= 0 && k + 1 < num2)
					{
						ary[i][j][k]++;
					}

					if (map[i][j - 1][k] == '*' && j - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i][j][k - 1] == '*' && k - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i][j - 1][k - 1] == '*' && j - 1 >= 0 && k - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i][j + 1][k] == '*' && j + 1 < num1)
					{
						ary[i][j][k]++;
					}
					if (map[i][j][k + 1] == '*' && k + 1 < num2)
					{
						ary[i][j][k]++;
					}
					if (map[i][j + 1][k + 1] == '*' && j + 1 < num1 && k + 1 < num2)
					{
						ary[i][j][k]++;
					}
					if (map[i][j + 1][k - 1] == '*' && j + 1 < num1 && k - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i][j - 1][k + 1] == '*' && j - 1 >= 0 && k + 1 < num2)
					{
						ary[i][j][k]++;
					}

					if (map[i + 1][j][k] == '*' && i + 1 < num3)
					{
						ary[i][j][k]++;
					}
					if (map[i + 1][j - 1][k] == '*' && i + 1 < num3 && j - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i + 1][j][k - 1] == '*' && i + 1 < num3 && k - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i + 1][j - 1][k - 1] == '*' && i + 1 < num3 && k - 1 >= 0 && j - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i + 1][j + 1][k] == '*' && i + 1 < num3 && j + 1 < num1)
					{
						ary[i][j][k]++;
					}
					if (map[i + 1][j][k + 1] == '*' && i + 1 < num3 && k + 1 < num2)
					{
						ary[i][j][k]++;
					}
					if (map[i + 1][j + 1][k + 1] == '*' && i + 1 < num3 && j + 1 < num1 && k + 1 < num2)
					{
						ary[i][j][k]++;
					}
					if (map[i + 1][j + 1][k - 1] == '*' && i + 1 < num3 && j + 1 < num1 && k - 1 >= 0)
					{
						ary[i][j][k]++;
					}
					if (map[i + 1][j - 1][k + 1] == '*' && i + 1 < num3 && j - 1 >= 0 && k + 1 < num2)
					{
						ary[i][j][k]++;
					}
				}


			}
		}

	}
	for (int i = 0; i < num3; i++)
	{
		for (int j = 0; j < num1; j++)
		{
			for (int k = 0; k < num2; k++)
			{
				if (ary[i][j][k] == -1)
				{
					printf("*");
				}
				else
				{
					printf("%d", ary[i][j][k] % 10);
				}

			}
			printf("\n");
		}
	}

}
