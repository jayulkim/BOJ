#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

unsigned long long int ary[3] = { 2,7,61};

unsigned long long int Pow(unsigned long long int a, unsigned long long int rd, unsigned long long int num)
{
	unsigned long long int result = 1;
	a %= num;
	while (rd > 0)
	{
		if (rd % 2 == 1)
		{
			result *= (a % num);
			result %= num;
		}
		a *= (a % num);
		a %= num;
		rd /= 2;
	}
	return result;
}
unsigned int millerlabin(unsigned long long int a, unsigned long long int num)
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
	unsigned long long int num1 = num - 1;
	while (1)
	{
		unsigned long long int temp = Pow(a, num1, num) % num;
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
	for (int i = 0; i < 3; i++)
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
	int num = 0;
	scanf("%d", &num);
	int result = 0;
	for (int i = 0; i < num; i++)
	{
		unsigned long long int num1 = 0;
		scanf("%llu", &num1);
		num1 *= 2;
		num1 += 1;
		if (isprime(num1) == 0)
		{
			result++;
		}
	}
	printf("%d", result);
}