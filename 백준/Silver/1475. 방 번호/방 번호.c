#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

int ary[1000005] = { 0, };

char num1[100];

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
int lower_bound(int* ary, int size, int key)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (ary[cen] >= key)
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
int upper_bound(int* ary, int size, int key)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (ary[cen] > key)
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
	scanf("%s", num1);

	int num2 = strlen(num1);

	for (int i = 0; i < num2; i++)
	{
		//printf("%d ", num1[i]);
		ary[i] = num1[i] - 48;
		//printf("%d ", ary[i]);
	}
	qsort(ary, num2, sizeof(int), compare);
	ary[num2] = 10;
	int max = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i != 6 && i != 9)
		{
			int result = upper_bound(ary, num2 + 1, i) - lower_bound(ary, num2 + 1, i);
			// printf("%d", result);
			if (result > max)
			{
				max = result;
			}
		}
		else
		{
			int result1 = upper_bound(ary, num2 + 1, 6) - lower_bound(ary, num2 + 1, 6);
			int result2 = upper_bound(ary, num2 + 1, 9) - lower_bound(ary, num2 + 1, 9);
			if (((result1 + result2) / 2 + (result1 + result2) % 2) > max)
			{
				max = ((result1 + result2) / 2 + (result1 + result2) % 2);
			}
		}
	}
	printf("%d\n", max);
}