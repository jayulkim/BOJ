#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[1000009] = { 0, };
int sum[1000009] = { 0, };

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
		scanf("%d", &ary[i]);
	}

	qsort(ary, num1, sizeof(int), compare);

	int index = 0;
	for (int i = 0; i < num1 - 2; i++)
	{
		if (ary[i] + ary[i + 1] > ary[i + 2])
		{
			sum[index] = ary[i] + ary[i + 1] + ary[i + 2];
			index++;
		}
	}
	if (index == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", sum[index - 1]);
	}
	
}