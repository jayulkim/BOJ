#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	long long int result = 0;
	x %= num;
	y %= num;
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

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	if (num1 == 0)
	{
		long long int num2 = 0;
		scanf("%lld", &num2);
		long long int m = 0;
		scanf("%lld", &m);
		printf("%lld", num2 % m);
	}
	else if (num1 == 1)
	{
		long long int num2 = 0;
		long long int num3 = 0;
		scanf("%lld %lld", &num2, &num3);
		long long int m = 0;
		scanf("%lld", &m);
		printf("%lld", powmod(num3, num2, m) % m);
	}
	else if (num1 == 2)
	{
		long long int num2 = 0;
		long long int num3 = 0;
		long long int num4 = 0;
		scanf("%lld %lld %lld", &num2, &num3, &num4);
		long long int m = 0;
		scanf("%lld", &m);
		long long int num5 = powmod(num3, num2, m - 1) % (m - 1);
		if (num5 == 0)
		{
			num5 += (m - 1);
		}
		printf("%lld", powmod(num4, num5, m) % m);
	}
}