#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

typedef struct info
{
	char name[20];
	int year;
	int month;
	int day;
}info;

info list[105];

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;

	if (a->year > b->year)
	{
		return 1;
	}
	else if (a->year < b->year)
	{
		return -1;
	}
	else
	{
		if (a->month > b->month)
		{
			return 1;
		}
		else if (a->month < b->month)
		{
			return -1;
		}
		else
		{
			if (a->day > b->day)
			{
				return 1;
			}
			else if (a->day < b->day)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s %d %d %d", list[i].name, &list[i].day, &list[i].month, &list[i].year);
	}
	qsort(list, num1, sizeof(info), compare);
	printf("%s\n%s", list[num1 - 1].name, list[0].name);

}