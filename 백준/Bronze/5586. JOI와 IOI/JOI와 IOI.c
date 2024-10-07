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
	char str1[10000];

	gets(str1);

	int num1 = strlen(str1);

	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < num1 - 2; i++)
	{
		if (str1[i] == 'J' && str1[i + 1] == 'O' && str1[i + 2] == 'I')
		{
			count1++;
		}
		if (str1[i] == 'I' && str1[i + 1] == 'O' && str1[i + 2] == 'I')
		{
			count2++;
		}
	}
	printf("%d\n%d", count1, count2);

}