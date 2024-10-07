#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[100005] = { 0, };

int sum[100005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	sum[0] = ary[0];
	for (int i = 1; i < num1; i++)
	{
		sum[i] = sum[i - 1] + ary[i];
	}

	int start = 0;
	int end = 0;

	int min = 100001;
	for (int i = 0; i < num1; i++)
	{
		//printf("%d ", sum[i]);
		if (sum[i] >= num2)
		{
			min = i + 1;
			break;
		}
	}
	while (end < num1)
	{
		if (sum[end] - sum[start] >= num2)
		{
			if (end - start < min)
			{
				min = end - start;
			}
			start++;
			//end++;
		}
		else if (sum[end] - sum[start] < num2)
		{
			end++;
		}
		if (start == end)
		{
			end++;
		}
	}
	if (min == 100001)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", min);
	}
	
	
}