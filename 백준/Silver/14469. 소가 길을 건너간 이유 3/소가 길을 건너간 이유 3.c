#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

typedef struct info
{
	int time;
	int count;
}info;

info list[105];

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;

	if (a->time > b->time)
	{
		return 1;
	}
	else if (a->time < b->time)
	{
		return -1;
	}
	else
	{
		if (a->count > b->count)
		{
			return 1;
		}
		else if (a->count < b->count)
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
		scanf("%d %d", &list[i].time, &list[i].count);
	}
	qsort(list, num1, sizeof(info), compare);

	int sum = 0;
	for (int i = 0; i < num1; i++)
	{
		if (sum < list[i].time)
		{
			sum = list[i].time + list[i].count;
		}
		else
		{
			sum += list[i].count;
		}
	}
	printf("%d\n", sum);

}