#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int ary[1000001] = { 0, };
int prime[78499] = { 0, };
int map[1000001] = { 0, };
int result[101][78499] = { 0, };
int main(void)
{
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 1000000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (int i = 2; i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
	//printf("%d", index);
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int index1 = 0;
		int index2 = 0;
		int num2 = 0;
		scanf("%d", &num2);
		while (num2 > 1)
		{
			if (num2 % prime[index1] == 0)
			{
				map[prime[index1]]++;
				result[i][prime[index1]]++;
				num2 /= prime[index1];
			}
			else
			{
				index1++;
			}
		}
	}
	int result1 = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		for (int j = 0; j < map[i] / num1; j++)
		{
			result1 *= i;
		}
	}
	int result2 = 0;
	for (int i = 0; i < num1; i++)
	{
		for (int j = 2; j <= 78498; j++)
		{
			if (result[i][j] < map[j] / num1)
			{
				result2 += (map[j] / num1 - result[i][j]);
			}
		}
	}
	printf("%d %d", result1, result2);
}