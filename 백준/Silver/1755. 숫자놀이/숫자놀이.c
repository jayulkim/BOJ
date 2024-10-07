#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[11][10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

typedef struct info
{
	char num1[10];
	char num2[10];
	int number;
}info;

info list[105];

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;

	if (strcmp(a->num1, b->num1) == 0)
	{
		if (strcmp(a->num2, b->num2) > 0)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return strcmp(a->num1, b->num1);
	}

}

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);

	for (int i = num1; i <= num2; i++)
	{
		list[i].number = i;
		if (i < 10)
		{
			strcpy(list[i].num1, str[i]);
		}
		else if (i >= 10)
		{
			int num3 = i / 10;
			int num4 = i % 10;
			strcpy(list[i].num1, str[num3]);
			strcpy(list[i].num2, str[num4]);
		}
		//printf("%s %s\n", list[i].num1,list[i].num2);
	}

	int count = 0;
	qsort(list, num2 + 1, sizeof(info), compare);
	for (int i = num1; i <= num2; i++)
	{
		count++;
		printf("%d ", list[i].number);
		if (count == 10)
		{
			printf("\n");
			count = 0;
		}
	}
}