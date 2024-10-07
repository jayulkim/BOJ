#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
long long int ary[3] = { 2,3,61 };
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
	for (int i = 0; i < 3; i++)
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
int compare(const void* num1, const void* num2)
{
	long long int a = *(long long int*)num1;
	long long int b = *(long long int*)num2;
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
long long int soinsoo[1001] = { 0, };
int index = 1;
long long int oilerpi(long long int* soinsoo)
{
	long long int result = 1;
	for (int i = 1; i < index; i++)
	{
		if (soinsoo[i - 1] != soinsoo[i])
		{
			result *= (soinsoo[i] - 1);
		}
		else
		{
			result *= soinsoo[i];
		}
	}
	return result;
}
int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		long long int n = 0;
		scanf("%lld", &n);
		n++;
		while (n > 1)
		{
			long long int temp = pollardrho(n);
			soinsoo[index++] = temp;
			n /= temp;
		}
		qsort(soinsoo, index, sizeof(long long int), compare);
		printf("%lld\n",oilerpi(soinsoo));
		index = 1;
	}
}