#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct info
{
	char kind[25];
}info;

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	return strcmp(a->kind, b->kind);
}


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		info list[35];
		int ary[35] = { 0, };
		int index = 0;
		int num2 = 0;
		scanf("%d", &num2);
		for (int j = 0; j < num2; j++)
		{
			char name[25];
			scanf("%s %s", name, list[j].kind);
		}
		qsort(list, num2, sizeof(info), compare);
		for (int j = 0; j < num2; j++)
		{
		//	printf("%s\n", list[j].kind);
			if (strcmp(list[j].kind, list[j+1].kind) != 0)
			{
				ary[index]+=2;
				index++;
			}
			else
			{
				ary[index]++;
			}
		}
		int result = 1;
		for (int j = 0; j < index; j++)
		{
			//printf("%d ", ary[j]);
			if (ary[j] != 0)
			{
				result *= ary[j];
			}
		
		}
		printf("%d\n", result - 1);
	}
}