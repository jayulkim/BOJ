#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ary[11][11];

int main(void)
{
	int row = 0, col = 0;
	scanf("%d %d", &row, &col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf(" %c", &ary[i][j]);
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = col - 1; j > -1; j--)
		{
			printf("%c", ary[i][j]);
		}
		printf("\n");
	}
}
