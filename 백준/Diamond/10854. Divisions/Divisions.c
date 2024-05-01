#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long long int ary[12] = { 2,3,5,7,11,13,17,19,23,29,31,37 };

long long int mulmod(long long int x, long long int y, long long int num) 
{
	x %= num;
	y %= num;
	long long int result = 0;
	while (y > 0) 
	{
		if (y % 2 == 1)
		{
			result += (x % num);
			result %= num;
		}
		x += (x % num);
		x %= num;
		y /= 2;
	}
	return result;
}

long long int Pow(long long int a, long long int rd, long long int num)
{
	if (rd == 0)
	{
		return 1LL;
	}
	long long int count = Pow(a, rd / 2, num) % num;
	if (rd % 2 == 0)
	{
		return mulmod(count % num, count % num, num) % num;
	}
	else
	{
		return mulmod(mulmod(count % num, count % num, num) % num, a % num, num);
	}
}

int millerlabin(long long int num, long long int a)
{
	if (num < 2)
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
		long long int temp = Pow(a, num1, num) % num;
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
		if (millerlabin(num, ary[i]) == 1)
		{
			return 1;
		}
	}
	return 0;
}

long long int Random(long long int x, long long int c, long long int num)
{
	return (mulmod(x, x, num) % num + c % num) % num;
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

long long int ary1[65] = { 0, };
int index = 0;

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

int main(void)
{
	long long int num1 = 0;
	scanf("%lld", &num1);
	if (isprime(num1) == 0)
	{
		printf("2");
		return 0;
	}
	while (num1 > 1)
	{
		long long int num2 = pollardrho(num1);
		ary1[index++] = num2;
		num1 /= num2;
	}
	long long int result = 1;
	qsort(ary1, index, sizeof(long long int), compare);
	long long int count = 0;
	for (int i = 0; i < index; i++)
	{
		if (ary1[i] != ary1[i + 1])
		{
			count+=2;
			result *= count;
			count = 0;
		}
		else
		{
			count++;
		}
	}
	printf("%lld", result);
}