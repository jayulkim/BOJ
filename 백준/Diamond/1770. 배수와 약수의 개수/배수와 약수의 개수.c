#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <memory.h>

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
unsigned long long int Random(unsigned long long int x, unsigned long long int c, unsigned long long int num)
{
	return (mulmod(x, x, num) % num + c) % num;
}
unsigned long long int gcd(unsigned long long int num1, unsigned long long int num2)
{
	unsigned long long int temp = num1 % num2;
	while (temp > 0)
	{
		num1 = num2;
		num2 = temp;
		temp = num1 % num2;
	}
	return num2;
}
unsigned long long int pollardrho(unsigned long long int num)
{
	if (num % 2 == 0)
	{
		return 2;
	}
	if (isprime(num) == 0)
	{
		return num;
	}
	unsigned long long int x = (rand() % (num - 2)) + 1;
	unsigned long long int y = x;
	unsigned long long int c = (rand() % 3) * 2 - 1;
	unsigned long long int d = 1;
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
unsigned long long int ary1[1001] = { 0, };
unsigned long long int index1 = 0;

int compare(const void* num1, const void* num2)
{
	unsigned long long int a = *(unsigned long long int*)num1;
	unsigned long long int b = *(unsigned long long int*)num2;
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

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		unsigned long long int num2 = 0;
		scanf("%llu", &num2);
		if (num2 == 1)
		{
			printf("1\n");
		}
		else
		{
			unsigned long long int num4 = num2;
			while (num2 > 1)
			{
				unsigned long long int num3 = pollardrho(num2);
				ary1[index1++] = num3;
				num2 /= num3;
			}
			qsort(ary1, index1, sizeof(unsigned long long int), compare);
			int count = 0;
			for (unsigned long long int j = 0; j < index1; j++)
			{
				if (ary1[j] == ary1[j + 1])
				{
					count++;
					break;
				}
			}
			if (count == 0)
			{
				unsigned long long int result = 1;
				for (unsigned long long int j = index1; j >= 1; j--)
				{
					result *= j;
				}
				printf("%llu\n", result);
			}
			else
			{
				if (num4 == 4)
				{
					printf("1\n");
				}
				else
				{
					printf("-1\n");
				}
			}
		}
		memset(ary1, 0, sizeof(ary1));
		index1 = 0;
	}
}