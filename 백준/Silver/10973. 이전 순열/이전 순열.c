#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[10005] = { 0, };
int ary1[10005] = { 0, };

void swap(int* num1, int* num2)
{
	int c = *num1;
	*num1 = *num2;
	*num2 = c;
}

int compare(const void* num1, const void* num2)
{
	int a = *(int*)num1;
	int b = *(int*)num2;
	if (a > b)
	{
		return -1;
	}
	else if (a < b)
	{
		return 1;
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
	int count = 0;
	for (int i = num1 - 1; i >= 1; i--)
	{
		if (ary[i] < ary[i - 1])
		{
			int max = 0;
			int index = 0;
			count++;
			for (int j = i; j < num1; j++)
			{
				if (ary[j] < ary[i - 1])
				{
					if (max < ary[j])
					{
						max = ary[j];
						index = j;
					}
				}
			}
			int index1 = 0;
			swap(&ary[i - 1], &ary[index]);
			for (int j = i; j < num1; j++)
			{
				ary1[index1] = ary[j];
				index1++;
			}
			int index2 = 0;
			qsort(ary1, index1, sizeof(int), compare);
			for (int j = i; j < num1; j++)
			{
				ary[j] = ary1[index2];
				index2++;
			}
			break;
		}
	}
	if (count == 0)
	{
		printf("-1\n");
	}
	else
	{
		for (int i = 0; i < num1; i++)
		{
			printf("%d ", ary[i]);
		}
	}
	//printf("%d\n", count);
	
}