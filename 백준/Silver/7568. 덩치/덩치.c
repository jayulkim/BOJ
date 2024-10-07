#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct info
{
	int high;
	int weight;
	int index;
	int level;
}info;

info list[60];

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->high > b->high && a->weight > b->weight)
	{
		return -1;
	}
	else if (a->high < b->high && a->weight < b->weight)
	{
		return 1;
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
	if (a->index > b->index)
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
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d", &list[i].weight, &list[i].high);
		list[i].index = i;
	}
	//qsort(list, num1, sizeof(info), compare);

	
	int count1 = 0;
	for (int i = 0; i < num1; i++)
	{
		int count = 1;
	//	printf("%d %d\n", list[i].weight, list[i].high);
		for (int j = 0; j < num1; j++)
		{
			if (list[i].weight <list[j].weight && list[i].high < list[j].high)
			{
				count++;
			}
			else if ((list[i].weight < list[j].weight && list[i].high >= list[j].high) || (list[i].weight >= list[j].weight && list[i].high < list[j].high) || (list[i].weight == list[j].weight && list[i].high == list[j].high))
			{
				continue;
			}
		}
		printf("%d ", count);
	}
	


}