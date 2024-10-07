#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ary[1000005] = { 0, };
int sum[1000005] = { 0, };

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
	for (int i = 1; i < num2; i++)
	{
		sum[i] = sum[i - 1] + ary[i];
	}
	for (int i = num2; i < num1; i++)
	{
		sum[i] = sum[i - 1] - ary[i - num2] + ary[i];
	}
	int count = 0;
	for (int i = 0; i < num1; i++)
	{
		//printf("%d ", sum[i]);
		if (sum[i] >= 129 && sum[i] <= 138)
		{
			count++;
		}
	}
	printf("%d\n", count);

}

