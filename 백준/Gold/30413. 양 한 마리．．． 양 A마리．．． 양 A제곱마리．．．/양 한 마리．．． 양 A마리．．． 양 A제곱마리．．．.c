#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

long long int addmod(long long int x, long long int y, long long int num)
{
	x %= num;
	y %= num;
	if (num - y <= x)
	{
		return x - (num - y);
	}
	else
	{
		return x + y;
	}
}
long long int mulmod(long long int x, long long int y, long long int num)
{
	x %= num;
	y %= num;
	long long int result = 0;
	while (y > 0)
	{
		if (y % 2 == 1)
		{
			result = addmod(result, x, num);
			result %= num;
		}
		x = addmod(x, x, num);
		x %= num;
		y /= 2;
	}
	return result;
}
long long int powmod(long long int x, long long int y, long long int num)
{
	x %= num;
	long long int result = 1;
	while (y > 0)
	{
		if (y % 2 == 1)
		{
			result = mulmod(result, x, num);
			result %= num;
		}
		x = mulmod(x, x, num);
		x %= num;
		y /= 2;
	}
	return result;
}
long long int arysum(long long int a, long long int b, long long int num)
{
	if (b == 1)
	{
		return 1;
	}
	if (b % 2 == 0)
	{
		long long int count = arysum(a, b / 2, num) % num;
		return mulmod(addmod(1, powmod(a, b / 2, num), num), count, num);
	}
	else
	{
		long long int count = arysum(a, (b + 1) / 2, num) % num;
		return (mulmod(addmod(1, powmod(a, (b + 1) / 2, num), num), count, num) - powmod(a, b, num) % num + num) % num;
	}
}

int main(void)
{
	int a = 0;
	long long int b = 0;
	scanf("%d %lld", &a, &b);
	printf("%lld", arysum(a, b, 1000000007) % 1000000007);
}