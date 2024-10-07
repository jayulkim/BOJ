#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[200002] = { 0, };

int compare(const void* num1, const void* num2)
{
	int a = *(int*)num1;
	int b = *(int*)num2;
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
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
		scanf("%d %d %d %d %d", &ary[0], &ary[1], &ary[2], &ary[3], &ary[4]);

		qsort(ary, 5, sizeof(int), compare);
		if (ary[3] - ary[1] >= 4)
		{
			printf("KIN\n");
		}
		else
		{
			printf("%d\n",  ary[1] + ary[2] + ary[3]);
		}

	}
	
}