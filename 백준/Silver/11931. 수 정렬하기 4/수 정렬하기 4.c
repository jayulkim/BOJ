#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

int search(long long int* ary, int size, long long int key)
{
	int start = 0, end = size - 1;
	while (start <= end)
	{
		int cen = (start + end) / 2;

		if (ary[cen] == key)
		{
			return cen;
		}
		else if (ary[cen] > key)
		{
			end = cen - 1;
		}
		else if (ary[cen] < key)
		{
			start = cen + 1;
		}
	}
	return -1;
}

int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	int* ary1 = (int*)malloc(sizeof(int) * 1000000);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary1[i]);
		
	}
	qsort(ary1, num1, sizeof(int), compare);

	for (int i = num1 - 1; i >= 0; i--)
	{
		printf("%d\n", ary1[i]);
	}
	free(ary1);

}