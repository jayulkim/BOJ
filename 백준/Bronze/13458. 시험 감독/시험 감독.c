#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

long long int ary[1000000] = { 0, };
int main(void)
{
	long long int num1 = 0;

	long long int num2 = 0;
	long long int num3 = 0;

	scanf("%lld", &num1);

	long long int count = 0;

	for (long long int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
	}

	scanf("%lld %lld", &num2, &num3);

	for (long long int i = 0; i < num1; i++)
	{
		ary[i] -= num2;
		count++;
		if (ary[i] / num3 != 0 && ary[i] % num3 != 0 && ary[i] > 0)
		{
			count = count + ary[i] / num3 + 1;
		}
		else if (ary[i] / num3 != 0 && ary[i] % num3 == 0 && ary[i] > 0)
		{
			count = count + ary[i] / num3;
		}
		else if (ary[i] / num3 == 0 && ary[i] > 0)
		{
			count++;
		}

	}
	printf("%lld", count);

}
