#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
long long int** arymul(long long int** x, long long int** y, long long int num)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			x[i][j] %= num;
			y[i][j] %= num;
		}
	}
	long long int** result = (long long int**)malloc(sizeof(long long int) * 2);
	for (int i = 0; i < 2; i++)
	{
		result[i] = (long long int*)malloc(sizeof(long long int) * 2);
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			long long int sum = 0;
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
long long int** arypow(long long int** x, long long int n, long long int num)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			x[i][j] %= num;
		}
	}
	long long int** result = (long long int**)malloc(sizeof(long long int) * 2);
	for (int i = 0; i < 2; i++)
	{
		result[i] = (long long int*)malloc(sizeof(long long int) * 2);
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
char a0[3];
char a1[3];
int main(void)
{
	long long int x = 0, y = 0, n = 0;
	scanf("%lld %lld %s %s %lld", &x, &y, a0, a1, &n);
	long long int** result = (long long int**)malloc(sizeof(long long int) * 2);
	for (int i = 0; i < 2; i++)
	{
		result[i] = (long long int*)malloc(sizeof(long long int) * 2);
	}
	result[0][0] = x;
	result[0][1] = y;
	result[1][0] = 1;
	result[1][1] = 0;
	long long int** yy = (long long int**)malloc(sizeof(long long int) * 2);
	for (int i = 0; i < 2; i++)
	{
		yy[i] = (long long int*)malloc(sizeof(long long int) * 2);
	}
	if (a0[0] == '0')
	{
		yy[1][0] = atoi(&a0[1]);
	}
	else
	{
		yy[1][0] = atoi(a0);
	}
	if (a1[0] == '0')
	{
		yy[0][0] = atoi(&a1[1]);
	}
	else
	{
		yy[0][0] = atoi(a1);
	}
	if (n == 0)
	{
		printf("%s", a0);
	}
	else if (n == 1)
	{
		printf("%s",a1);
	}
	else
	{
		long long int** result1 = (long long int**)malloc(sizeof(long long int) * 2);
		for (int i = 0; i < 2; i++)
		{
			result1[i] = (long long int*)malloc(sizeof(long long int) * 2);
		}
		result1 = arypow(result, n - 1, 100);
		if (addmod(mulmod(result1[0][0], yy[0][0], 100), mulmod(result1[0][1], yy[1][0], 100), 100) % 100 < 10)
		{
			printf("0%lld", addmod(mulmod(result1[0][0], yy[0][0], 100), mulmod(result1[0][1], yy[1][0], 100), 100) % 100);
		}
		else
		{
			printf("%lld", addmod(mulmod(result1[0][0], yy[0][0], 100), mulmod(result1[0][1], yy[1][0], 100), 100) % 100);
		}
	}
}