#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary1[1000000];
int ary2[1000000];

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
	int num = 0;
	scanf("%d", &num);
	for (int j = 0; j < num; j++)
	{
		int num1 = 0;

		scanf("%d", &num1);

		for (int i = 0; i < num1; i++)
		{
			scanf("%d", &ary1[i]);
		}

		int num2 = 0;
		scanf("%d", &num2);

		for (int i = 0; i < num2; i++)
		{
			scanf("%d", &ary2[i]);
		}

		qsort(ary1, num1, sizeof(int), compare);

		for (int i = 0; i < num2; i++)
		{
			int result = search(ary1, num1, ary2[i]);

			if (result != -1)
			{
				ary2[i] = 1;
			}
			else
			{
				ary2[i] = 0;
			}
		}
		for (int i = 0; i < num2; i++)
		{
			printf("%d\n", ary2[i]);
		}

	}
	

}