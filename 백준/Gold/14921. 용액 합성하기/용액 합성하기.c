#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>

int ary[100005] = { 0, };

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

	int min = 300000000;
	int count = 0;
	int start = 0;
	int end = num1 - 1;
	while (start < end)
	{
		int num2 = abs(ary[end] + ary[start]);
		if (ary[end] + ary[start] < 0)
		{
			start++;
			if (num2 < min)
			{
				count = 1;
				min = num2;
			}
			
		}
		else if (ary[end] + ary[start] > 0)
		{
			end--;
			if (num2 < min)
			{
				count = 2;
				min = num2;
			}
			
		}
		else
		{
			printf("0\n");
			return 0;
		}

	}
	if (count == 1)
	{
		printf("%d\n", -min);
	}
	else if (count == 2)
	{
		printf("%d\n", min);
	}
}