#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

typedef struct pos
{
	int x;
	int y;
}pos;

int compare(const void* num1, const void* num2)
{
	pos* a = (pos*)num1;
	pos* b = (pos*)num2;
	if (a->x > b->x)
	{
		return 1;
	}
	else if (a->x < b->x)
	{
		return -1;
	}
	else
	{
		if (a->y > b->y)
		{
			return 1;
		}
		else if(a->y < b->y)
		{
			return -1;
		}
		else
		{
			return 0;
		}
			
	}
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int count = 0;
		pos list[10];
		for (int j = 0; j < 4; j++)
		{
			scanf("%d %d", &list[j].x, &list[j].y);
		}
		qsort(list, 4, sizeof(pos), compare);
		
		int dis1 = (list[2].x - list[0].x) * (list[2].x - list[0].x) + (list[2].y - list[0].y) * (list[2].y - list[0].y);
		int dis2 = (list[1].x - list[0].x) * (list[1].x - list[0].x) + (list[1].y - list[0].y) * (list[1].y - list[0].y);

		int dis3 = (list[3].x - list[1].x) * (list[3].x - list[1].x) + (list[3].y - list[1].y) * (list[3].y - list[1].y);
		int dis4 = (list[3].x - list[2].x) * (list[3].x - list[2].x) + (list[3].y - list[2].y) * (list[3].y - list[2].y);

		if (dis1 == dis2 && dis2 == dis3 && dis3 == dis4)
		{
			int dis5 = (list[3].x - list[0].x) * (list[3].x - list[0].x) + (list[3].y - list[0].y) * (list[3].y - list[0].y);
			int dis6 = (list[2].x - list[1].x) * (list[2].x - list[1].x) + (list[2].y - list[1].y) * (list[2].y - list[1].y);
			if (dis5 == dis2 + dis3 && dis6 == dis1 + dis4)
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else
		{
			printf("0\n");
		}


	}

	
}