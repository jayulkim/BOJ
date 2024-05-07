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

long long int solve(long long int a, long long int r, long long int n, long long int mod)
{
	if (n == 1)
	{
		return a;
	}
	if (n % 2 == 0)
	{
		long long int count = solve(a, r, n / 2, mod);
		return mulmod(addmod(1, powmod(r, n / 2, mod), mod), count, mod) % mod;
	}
	else
	{
		long long int count = solve(a, r, (n + 1) / 2, mod);
		return (mulmod(addmod(1, powmod(r, (n + 1) / 2, mod), mod), count, mod) % mod - mulmod(a, powmod(r, n, mod), mod) % mod + mod) % mod;
	}
}

int main(void)
{
	long long int a = 0, r = 0, n = 0, mod = 0;
	scanf("%lld %lld %lld %lld", &a, &r, &n, &mod);
	printf("%lld", solve(a, r, n, mod) % mod);
}