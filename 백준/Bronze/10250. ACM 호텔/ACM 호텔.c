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

	int floor = 0;
	int room = 0;
	int count = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d %d", &floor, &room, &count);
		
		if (count % floor != 0)
		{
			printf("%d\n", (count % floor) * 100 + (count / floor) + 1);

		}
		if (count % floor == 0)
		{
			printf("%d\n", (floor * 100) + count / floor);
		}
		


	}

}