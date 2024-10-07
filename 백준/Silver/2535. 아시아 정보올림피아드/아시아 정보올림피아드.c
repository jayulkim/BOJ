#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info
{
	int cunt;
	int number;
	int score;
}info;

info list[1000];


int comparescore(const void* num1, const void* num2)
{
	info *a = (info*)num1;
	info *b = (info*)num2;

	if (a->score > b->score)
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



int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d %d", &list[i].cunt, &list[i].number, &list[i].score);


	}
	qsort(list, num1, sizeof(info), comparescore);

	if (list[num1 - 1].cunt == list[num1 - 2].cunt && list[num1 - 2].cunt == list[num1 - 3].cunt)
	{
		for (int i = num1 - 1; i >= num1 - 2; i--)
		{
			printf("%d %d\n", list[i].cunt, list[i].number);
		}
		for (int i = 0; i < num1; i++)
		{
			if (list[i].cunt == list[num1 - 1].cunt)
			{
				list[i].score = 0;
			}
		}
		qsort(list, num1, sizeof(info), comparescore);

		printf("%d %d\n", list[num1 - 1].cunt, list[num1 - 1].number);
	}
	else
	{
		for (int i = num1 - 1; i >= num1 - 3; i--)
		{
			printf("%d %d\n", list[i].cunt, list[i].number);
		}
	}
}