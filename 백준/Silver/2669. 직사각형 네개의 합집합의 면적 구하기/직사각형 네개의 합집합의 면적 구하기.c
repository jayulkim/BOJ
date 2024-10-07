#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int map[105][105] = { 0, };

typedef struct pos
{
	int startx;
	int starty;
	
	int endx;
	int endy;
}pos;

pos list[10];

int main(void)
{
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d %d %d", &list[i].startx, &list[i].starty, &list[i].endx, &list[i].endy);

		for (int k = list[i].starty; k < list[i].endy; k++)
		{
			for (int j = list[i].startx; j < list[i].endx; j++)
			{
				map[k][j] = 1;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			sum += map[i][j];
		}
	}

	printf("%d\n", sum);
}