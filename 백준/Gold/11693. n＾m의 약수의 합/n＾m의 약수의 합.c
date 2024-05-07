#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
long long int ary[12] = { 2,3,5,7,11,13,17,19,23,29,31,37 };
int millerlabin(long long int a, long long int num)
{
	if (num == 1)
	{
		return 1;
	}
	if (num == 2)
	{
		return 0;
	}
	if (num == a)
	{
		return 0;
	}
	long long int num1 = num - 1;
	while (1)
	{
		long long int temp = powmod(a, num1, num) % num;
		if (temp == num - 1)
		{
			return 0;
		}
		else
		{
			if (num1 % 2 == 0)
			{
				num1 /= 2;
			}
			else
			{
				if (temp == num - 1 || temp % num == 1)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
	}
}
int isprime(long long int num)
{
	for (int i = 0; i < 12; i++)
	{
		if (millerlabin(ary[i], num) == 1)
		{
			return 1;
		}
	}
	return 0;
}
long long int gcd(long long int num1, long long int num2)
{
	long long int temp = num1 % num2;
	while (temp > 0)
	{
		num1 = num2; 
		num2 = temp;
		temp = num1 % num2;
	}
	return num2;
}
long long int Random(long long int x, long long int c, long long int num)
{
	return (mulmod(x, x, num) % num + c) % num;
}
long long int pollardrho(long long int num)
{
	if (num % 2 == 0)
	{
		return 2;
	}
	if (isprime(num) == 0)
	{
		return num;
	}
	long long int x = (rand() % (num - 2)) + 1;
	long long int y = x;
	long long int c = (rand() % 3) * 2 - 1;
	long long int d = 1;
	while (gcd(d, num) == 1)
	{
		x = Random(x, c, num) % num;
		y = Random(y, c, num) % num;
		y = Random(y, c, num) % num;
		d = llabs(x - y);
		if (gcd(d, num) == num)
		{
			return pollardrho(gcd(d, num));
		}
	}
	if (isprime(gcd(d, num)) == 0)
	{
		return gcd(d, num);
	}
	else
	{
		return pollardrho(gcd(d, num));
	}
}
long long int sumary(long long int r, long long int m, long long int num)
{
	if (m == 1)
	{
		return 1;
	}
	if (m % 2 == 0)
	{
		long long int count = sumary(r, m / 2, num) % num;
		return mulmod(addmod(1, powmod(r, m / 2, num), num), count, num) % num;
	}
	else
	{
		long long int count = sumary(r, (m + 1) / 2, num) % num;
		return (mulmod(addmod(1, powmod(r, (m + 1) / 2, num), num), count, num) % num - powmod(r, m, num) % num + num) % num;
	}
}
long long int sum[31625] = { 0, };

int main(void)
{
	long long int n = 0, m = 0;
	scanf("%lld %lld", &n, &m);
	while (n > 1)
	{
		long long int temp = pollardrho(n);
		if (temp > 31623)
		{
			sum[31624] = temp;
		}
		else
		{
			sum[temp]++;
		}
		n /= temp;
	}
	long long int result = 1;
	for (long long int i = 2; i <= 31623; i++)
	{
		if (sum[i] != 0)
		{
			result = mulmod(result, sumary(i, m * sum[i] + 1, 1000000007), 1000000007) % 1000000007;
		}
	}
	if (sum[31624] != 0)
	{
		result = mulmod(result, sumary(sum[31624], m + 1, 1000000007), 1000000007) % 1000000007;
	}
	printf("%lld", result % 1000000007);
}