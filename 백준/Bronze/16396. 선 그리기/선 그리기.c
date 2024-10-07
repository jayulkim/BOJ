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

pos list[1000005];

pos list1[1000005];

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
		else if (a->y < b->y)
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
		scanf("%d %d", &list[i].x, &list[i].y);
	}
	qsort(list, num1, sizeof(pos), compare);


	long long int sum = 0;
	long long int minx = list[0].x;
	list1[0].x = minx;

	long long int maxy = list[0].y;
	list1[0].y = maxy;

	int index = 0;
	
	for (int i = 1; i < num1; i++)
	{
		if (maxy < list[i].y)
		{
			if (list[i].x <= maxy)
			{
				maxy = list[i].y;
				list1[index].y = maxy;
			}
			else
			{		
				index++;
				list1[index].x = list[i].x;
				list1[index].y = list[i].y;
				minx = list[i].x;
				maxy = list[i].y;
			}
		}
		else
		{
			list1[index].y = maxy;
		}


	}
	for (int i = 0; i <= index; i++)
	{
		//printf("%d %d\n", list1[i].x, list1[i].y);
		sum += (list1[i].y - list1[i].x);
	}


	printf("%lld\n", sum);
}