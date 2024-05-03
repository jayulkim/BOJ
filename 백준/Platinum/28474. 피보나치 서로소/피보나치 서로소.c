#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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
	x %= num;
	y %= num;
	unsigned long long int result = 0;
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
unsigned long long int powmod(unsigned long long int x, unsigned long long int y, unsigned long long int num)
{
	x %= num;
	y %= num;
	unsigned long long int result = 1;
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
unsigned long long int Pow(unsigned long long int x, int y)
{
	unsigned long long int result = 1;
	while (y > 0)
	{
		if (y % 2 == 1)
		{
			result *= x;
		}
		x *= x;
		y /= 2;
	}
	return result;
}
int millerlabin(unsigned long long int a, unsigned long long int num)
{
	if (num == 1)
	{
		return 1;
	}
	if (num == 2)
	{
		return 0;
	}
	if (a == num)
	{
		return 0;
	}
	unsigned long long int num1 = num - 1;
	while (1)
	{
		unsigned long long int temp = powmod(a, num1, num) % num;
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
unsigned long long int Random(unsigned long long int x, unsigned long long int c, unsigned long long int num)
{
	return (mulmod(x, x, num) % num + c) % num;
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
int sum[31626] = { 0, };
unsigned long long int stack[65] = { 0, };
int head = -1;
void push(unsigned long long int* stack, unsigned long long int num)
{
	stack[++head] = num;
}
unsigned long long int oilerpi(unsigned long long int num)
{
	while (num > 1)
	{
		unsigned long long int num1 = pollardrho(num);
		if (num1 < 31625)
		{
			if (sum[num1] == 0)
			{
				push(stack, num1);
			}
			sum[num1]++;
		}
		else
		{
			sum[31625] = num1;
		}
		num /= num1;
	}
	unsigned long long int result = 1;
	if (sum[31625] != 0)
	{
		result *= (sum[31625] - 1);
	}
	for (int i = 0; i <= head; i++)
	{
		result *= (stack[i] - 1);
		result *= Pow(stack[i], sum[stack[i]] - 1);
	}
	memset(sum, 0, sizeof(sum));
	head = -1;
	return result;
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
			printf("0\n");
		}
		else
		{
			if (num2 % 2 == 0 && num2 != 2)
			{
				printf("%llu\n", oilerpi(num2) + oilerpi(num2 / 2));
			}
			else
			{
				printf("%llu\n", oilerpi(num2));
			}	
		}
	}
}