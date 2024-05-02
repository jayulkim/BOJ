#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

unsigned long long int ary[12] = { 2,3,5,7,11,13,17,19,23,29,31,37 };

unsigned long long int addmod(unsigned long long int x, unsigned long long int y, unsigned long long int num)
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

unsigned long long int mulmod(unsigned long long int x, unsigned long long int y, unsigned long long int num)
{
	unsigned long long int result = 0;
	x %= num;
	y %= num;
	while (y > 0)
	{
		if (y % 2 == 1)
		{
			result = addmod(result, x, num) % num;
			result %= num;
		}
		x = addmod(x, x, num) % num;
		x %= num;
		y /= 2;
	}
	return result;
}

unsigned long long int Powmod(unsigned long long int a, unsigned long long int rd, unsigned long long int num)
{
	a %= num;
	unsigned long long int result = 1;
	while (rd > 0)
	{
		if (rd % 2 == 1)
		{
			result = mulmod(result, a, num);
			result %= num;
		}
		a = mulmod(a, a, num);
		a %= num;
		rd /= 2;
	}
	return result;
}
int millerlabin(unsigned long long int a, unsigned long long int num)
{
	if (num == 1)
	{
		return 0;
	}
	if (num == 2)
	{
		return 1;
	}
	if (num == a)
	{
		return 0;
	}
	unsigned long long int num1 = num - 1;
	while (1)
	{
		unsigned long long int temp = Powmod(a, num1, num) % num;
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
				if (temp % num == 1 || temp == num - 1)
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
int isprime(unsigned long long int num)
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

int main(void)
{
	unsigned long long int num1 = 0;
	unsigned long long int num2 = 0;
	scanf("%llu %llu", &num1, &num2);
	for (unsigned long long int i = num1; i <= num2; i++)
	{
		if (isprime(i) == 0 || i == 9)
		{
			printf("%llu ", i);
		}
	}
}