#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int ary[20] = { 0, };

long long int sum[20][20] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < 15; i++)
	{
		ary[i] = i + 1;
	}
	sum[0][0] = ary[0];
	for (int j = 1; j < 15; j++)
	{
		sum[0][j] = sum[0][j - 1] + ary[j];
	}

	for (int i = 1; i < 15; i++)
	{
		sum[i][0] = sum[i - 1][0];
		for (int j = 1; j < 15; j++)
		{
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j];
		}
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			//printf("%d ", sum[i][j]);
		}
		//printf("\n");
	}
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int num3 = 0;
		scanf("%d", &num2);
		scanf("%d", &num3);

		if (num2 == 0)
		{
			printf("%d\n", ary[num3 - 1]);
		}
		else
		{
			printf("%lld\n", sum[num2 - 1][num3 - 1]);
		}
		

	}
}