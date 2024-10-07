#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

long long int ary[5000005] = { 0, };


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		long long int sum = 0;
		int num2 = 0;
		int num3 = 0;
		long long int num4 = 0;
		int count = 0;
		scanf("%d %d %lld", &num2, &num3, &num4);
		for (int j = 0; j < num2; j++)
		{
			scanf("%lld", &ary[j]);
		}
		if (num2 == num3)
		{
			for (int j = 0; j < num3; j++)
			{
				sum += ary[j];
			}
			if (sum < num4)
			{
				count++;
			}
			printf("%d\n", count);
		}
		else
		{
			for (int j = 0; j < num3 - 1; j++)
			{
				ary[j + num2] = ary[j];
			}

			for (int j = 0; j < num3; j++)
			{
				sum += ary[j];
			}
			if (sum < num4)
			{
				count++;
			}
			for (int j = 1; j < num2; j++)
			{
				sum -= ary[j - 1];
				sum += ary[j + num3 - 1];
				if (sum < num4)
				{
					count++;
				}
			}
			printf("%d\n", count);
		}
	}
}