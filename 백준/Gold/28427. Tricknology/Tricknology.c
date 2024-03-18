#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ary[1500005] = { 0, };

int ary1[500005] = { 0, };
int sum[500005] = { 0, };

int main(void)
{
	for (int i = 2; i <= 750000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * 2; j <= 1500000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	int count = 0;
	for (int j = 1; j < 500000 - 1; j++)
	{
		if (ary[2 * j + 3] == 0)
		{
			ary1[index]++;
		}
		if (ary[3 * (j + 2)] == 0)
		{
			ary1[index]++;
		}
		index++;
	}
	sum[0] = ary1[0];
	for (int j = 0; j < 499998; j++)
	{
		sum[j] = sum[j-1] + ary1[j];
		//printf("%d ", sum[j]);
	}

	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int num3 = 0;
		scanf("%d %d", &num2, &num3);

		if (num2 == 2)
		{
			printf("%d\n", sum[num3 - 3]);
		}
		else
		{
			printf("%d\n", sum[num3 - 3] - sum[num2 - 3]);
		}
	}
}