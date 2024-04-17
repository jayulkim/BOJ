#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ary[1000005] = { 0, };
int sum[1000005] = { 0, };
int sum1[1000005] = { 0, };
int main(void)
{
	int count = 0;
	int count1 = 0;
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (ary[i] == '\0')
		{
			for (int j = i * i; j <= 1000000; j += i)
			{
				ary[j] = '1';
			}
		}
	}
	sum[0] = 0;
	sum[1] = 0;
	sum[2] = 1;
	sum1[0] = 0;
	sum1[1] = 0;
	sum1[2] = 1;
	sum1[3] = 0;
	sum1[4] = 0;
	sum1[5] = 1;
	for (int i = 3; i <= 1000000; i++)
	{
		if (ary[i] == '\0')
		{
			sum[i] = sum[i - 1] + 1;
			if (i % 4 == 1)
			{
				sum1[i] = sum1[i - 1] + 1;
			}
			else
			{
				sum1[i] = sum1[i - 1];
			}
		}
		else
		{
			sum[i] = sum[i - 1];
			sum1[i] = sum1[i - 1];
		}
	}

	int num1 = 0;
	int num2 = 0;
	while (1)
	{
		scanf("%d %d", &num1, &num2);
		if (num1 == -1 && num2 == -1)
		{
			break;
		}
		if (num1 <= 0)
		{
			if (num2 <= 0)
			{
				printf("%d %d %d %d\n", num1, num2, 0, 0);
			}
			else
			{
				printf("%d %d %d %d\n", num1, num2, sum[num2] - sum[0], sum1[num2] - sum1[0]);
			}
		}
		else if (num2 <= 0)
		{
			printf("%d %d %d %d\n", num1, num2, 0, 0);
		}
		else if (num1 > 0 && num2 > 0)
		{
			printf("%d %d %d %d\n", num1, num2, sum[num2] - sum[num1 - 1], sum1[num2] - sum1[num1 - 1]);
		}
	}
}
