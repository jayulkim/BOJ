#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[4000005] = { 0, };
int ary1[4000005] = { 0, };
int sum[4000005] = { 0, };

int main(void)
{
	for (int i = 2; i <= 4000000; i++)
	{
		ary[i] = i;
	}
	for (int i = 2; i <= 4000000; i++)
	{
		if (ary[i] != 0)
		{
			for (int j = 2 * i; j <= 4000000; j += i)
			{
				ary[j] = 0;
			}
		}
	}

	int num1 = 0;
	scanf("%d", &num1);

	
	int index = 0;
	int count = 0;
	if (ary[num1] != 0)
	{
		count++;
	//	printf("%d\n", count);
		for (int i = 2; i < num1; i++)
		{
			if (ary[i] != 0)
			{
				ary1[index] = ary[i];
			//	printf("%d ", ary1[index]);
				index++;
			}
		}
	}
	else
	{
		for (int i = 2; i <= num1; i++)
		{
			if (ary[i] != 0)
			{
				ary1[index] = ary[i];
			//	printf("%d ", ary1[index]);
				index++;
			}
		}
	}
	
	
	sum[0] = ary1[0];
	for (int i = 1; i < index; i++)
	{
		sum[i] = sum[i - 1] + ary1[i];
	}
	for (int i = 0; i < index; i++)
	{
	//	printf("%d ", sum[i]);
		if (sum[i] == num1)
		{
			count++;
		}
	}
	//printf("\n%d", index);
	int start = 0;
	int end = 1;
	
	while (end < index)
	{
		if (sum[end] - sum[start] < num1)
		{
			end++;
		}
		else if (sum[end] - sum[start] > num1)
		{
			start++;
		}
		if (sum[end] - sum[start] == num1)
		{
			end++;
			start++;
			count++;
		}
		if (end == start)
		{
			end++;
		}

	}



	printf("%d\n", count);
	
}