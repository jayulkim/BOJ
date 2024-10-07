#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	int number;
	int gold;
	int silver;
	int bronze;
	int level;
}info;
info list[10005];

int compare1(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->number > b->number)
	{
		return 1;
	}
	else if (a->number < b->number)
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
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d %d %d", &list[i].number, &list[i].gold, &list[i].silver, &list[i].bronze);
	}
	
	qsort(list, num1, sizeof(info), compare1);

	int result = 1;
	for (int i = 0; i < num1; i++)
	{
		if (i != num2 - 1)
		{
			if (list[i].gold > list[num2 - 1].gold)
			{
				result++;
			}
			else if (list[i].gold == list[num2 - 1].gold)
			{
				if (list[i].silver > list[num2 - 1].silver)
				{
					result++;
				}
				else if (list[i].silver == list[num2 - 1].silver)
				{
					if (list[i].bronze > list[num2 - 1].bronze)
					{
						result++;
					}
				}
			}
			
		}
	}
	printf("%d\n", result);
	
}