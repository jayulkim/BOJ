#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary1[500005] = { 0, };

int ary2[500005] = { 0, };

int result1[500005] = { 0, };

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

int search(int* ary, int size, int key)
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
	int num2 = 0;
	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary1[i]);
	}
	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &ary2[i]);
	}
	qsort(ary2, num2, sizeof(int), compare);

	int count1 = 0;
	int index = 0;
	for (int i = 0; i < num1; i++)
	{
		int result = search(ary2, num2, ary1[i]);
		if (result == -1)
		{
			count1++;
			result1[index] = ary1[i];
			index++;
		}
	}
	qsort(result1, index, sizeof(int), compare);

	
	if (count1 == 0)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", count1);
		for (int i = 0; i < index; i++)
		{
			
			printf("%d ", result1[i]);
		}
	}

}