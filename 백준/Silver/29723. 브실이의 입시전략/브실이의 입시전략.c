#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info
{
	char name[30];
	int score;
}info;

info list[10000];
info list1[10000];

int comparescore(const void* num1, const void* num2)
{
	info *a = (info*)num1;
	info *b = (info*)num2;

	if (a -> score > b -> score)
	{
		return 1;
	}
	else if (a -> score < b -> score)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


int comparename(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;

	return strcmp(a->name, b->name);
}
int lower_bound(info* ary, int size, char* key)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (strcmp(ary[cen].name, key) >= 0)
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return end;
}

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	int count = 0;
	scanf("%d %d %d", &num1, &num2, &num3);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s %d", list[i].name, &list[i].score);
	}
	qsort(list, num1, sizeof(info), comparename);

	for (int i = 0; i < num3; i++)
	{

		scanf("%s", list1[i].name);

		int result = lower_bound(list, num1, list1[i].name);
		if (result != num1)
		{
			count += list[result].score;
			list[result].score = 0;
		}


	}

	qsort(list, num1, sizeof(info), comparescore);

	int count1 = count;
	int count2 = count;
	for (int i = 0; i < num2 - num3; i++)
	{
		count1 += list[i + num3].score;
		count2 += list[num1 - 1 - i].score;
	}
	printf("%d %d\n", count1, count2);
}