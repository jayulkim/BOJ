#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long double ary[10000005] = { 0, };

int main(void)
{
	for (long int i = 2; i <= 10000000; i++)
	{
		ary[i] = i;
	}

	for (int i = 2; i * i <= 10000000; i++)
	{
		if (ary[i] != 0)
		{
			for (int j = i * i; j <= 10000000; j += i)
			{
				ary[j] = 0;
			}
		}
	}
	long double num1 = 0;
	long double num2 = 0;
	scanf("%Lf %Lf", &num1, &num2);

	int count = 0;
	for (long long int i = 2; i <= 10000000; i++)
	{
		if (ary[i] != 0)
		{
			long double num3 = ary[i];

			while (ary[i] <= num2 / num3)
			{
				if (ary[i] >= num1 / num3)
				{
					count++;
				}
				num3 *= ary[i];
				//printf("%lld\n", num3);
			}
		}
	}

	printf("%d", count);
}