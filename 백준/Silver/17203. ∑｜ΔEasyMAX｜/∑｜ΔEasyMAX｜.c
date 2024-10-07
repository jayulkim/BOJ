#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ary[1005] = { 0, };
int sum[1005] = { 0, };
int result[1005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	
	for (int i = 0; i < num1 - 1; i++)
	{
		sum[i] = abs(ary[i + 1] - ary[i]);
		//printf("%d ", sum[i]);
	}
	result[0] = sum[0];
	for (int i = 1; i < num1 - 1; i++)
	{
		result[i] = result[i - 1] + sum[i];
	}
	for (int i = 0; i < num1 - 1; i++)
	{
		//printf("%d ", result[i]);
	}
	for (int i = 0; i < num2; i++)
	{
		int start = 0;
		int end = 0;
		scanf("%d %d", &start, &end);
		if (start == end)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", result[end - 2] - result[start - 2]);
		}
		
	}

}
