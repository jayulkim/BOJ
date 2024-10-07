#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary1[500000] = { 0, };
int ary2[500000] = { 0, };
int ary3[500000] = { 0, };
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
	int num1 = 0;
	int num2 = 0;

	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary1[i]);
	}
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &ary2[i]);
	}

	qsort(ary1, num1, sizeof(int), compare);
	ary1[num1] = ary1[num1 - 1];
	for (int i = 0; i < num2; i++)
	{
		int result1 = upper_bound(ary1, num1 + 1, ary2[i]);
		int result2 = lower_bound(ary1, num1 + 1, ary2[i]);
		ary3[i] = result1 - result2;

	}

	for (int i = 0; i < num2; i++)
	{
		printf("%d ", ary3[i]);
	}

}