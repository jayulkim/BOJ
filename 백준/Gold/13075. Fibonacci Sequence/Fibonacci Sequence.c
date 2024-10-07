#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
unsigned long long int** arymul(unsigned long long int** x, unsigned long long int** y, unsigned long long int num)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			x[i][j] %= num;
			y[i][j] %= num;
		}
	}
	unsigned long long int** result = (unsigned long long int**)malloc(sizeof(unsigned long long int) * 2);
	for (int i = 0; i < 2; i++)
	{
		result[i] = (unsigned long long int*)malloc(sizeof(unsigned long long int) * 2);
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			unsigned long long int sum = 0;
			for (int k = 0; k < 2; k++)
			{
				sum = addmod(sum, mulmod(x[i][k], y[k][j], num), num);
				sum %= num;
			}
			result[i][j] = sum;
			result[i][j] %= num;
		}
	}
	return result;
}
unsigned long long int** arypow(unsigned long long int** x, unsigned long long int n, unsigned long long int num)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			x[i][j] %= num;
		}
	}
	unsigned long long int** result = (unsigned long long int**)malloc(sizeof(unsigned long long int) * 2);
	for (int i = 0; i < 2; i++)
	{
		result[i] = (unsigned long long int*)malloc(sizeof(unsigned long long int) * 2);
		for (int j = 0; j < 2; j++)
		{
			result[i][j] = x[i][j];
		}
	}
	n -= 1;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			result = arymul(result, x, num);
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					result[i][j] %= num;
				}
			}
		}
		x = arymul(x, x, num);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				x[i][j] %= num;
			}
		}
		n /= 2;
	}
	return result;
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		unsigned long long int** ary = (unsigned long long int**)malloc(sizeof(unsigned long long int) * 2);
		for (int j = 0; j < 2; j++)
		{
			ary[j] = (unsigned long long int*)malloc(sizeof(unsigned long long int) * 2);
		}
		ary[0][0] = 1;
		ary[0][1] = 1;
		ary[1][0] = 1;
		ary[1][1] = 0;
		unsigned long long int num2 = 0;
		scanf("%llu", &num2);
		if (num2 == 1)
		{
			printf("1\n");
		}
		else if (num2 == 2)
		{
			printf("1\n");
		}
		else
		{
			printf("%llu\n", arypow(ary, num2 - 1, 1000000000)[0][0] % 1000000000);
		}	
	}
}