#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int ary[60] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
long long int ary1[60] = { 0, };

int main(void)
{
	int num1 = 0;
	long long int num2 = 0;
	int num3 = 0;
	scanf("%d %lld %d", &num1, &num2, &num3);

	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
	}
	int result = 0;
	int count = 0;
	for (int i = 0; i <= 50; i++)
	{
		if (ary[i] > num2)
		{
			result++;
		}
		if (ary[i] < num2)
		{
			break;
		}
	}
	for (int i = result; i <= 50; i++)
	{
		if (num2 == ary[i])
		{
			count++;
		}
	}
	if (count + result >= num3)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", result + 1);

	}

	


}