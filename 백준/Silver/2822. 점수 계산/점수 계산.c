#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

typedef struct info
{
	int index;
	int score;
}info;

info list[105];
info list1[105];

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;

	if (a->score > b->score)
	{
		return 1;
	}
	else if (a->score < b->score)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int compare1(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;

	if (a->index> b->index)
	{
		return 1;
	}
	else if (a->index < b->index)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &list[i].score);
		list[i].index = i + 1;
	}
	qsort(list, 8, sizeof(info), compare);

	int sum = 0;
	for (int i = 3; i < 8; i++)
	{
		sum += list[i].score;
		list1[i].index = list[i].index;
	}
	qsort(list1, 8, sizeof(info), compare1);
	printf("%d\n%d %d %d %d %d", sum, list1[3].index, list1[4].index, list1[5].index, list1[6].index, list1[7].index);

}