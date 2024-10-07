#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>

int ary[1000005] = { 0, };

int main(void)
{
	for (int i = 2; i <= 1000000; i++)
	{
		for (int j = 2 * i; j <= 1000000; j += i)
		{
			ary[j] += i;
		}
	}
	int num = 1;
	while (1)
	{
		int count = 0;
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;
		scanf("%d %d %d", &num1, &num2, &num3);
		if (num1 == 0 && num2 == 0 && num3 == 0)
		{
			break;
		}
		for (int i = num1; i <= num2; i++)
		{
			if (abs(i - ary[i] - 1) <= num3)
			{
				count++;
			}
		}
		printf("Test %d: %d\n",num, count);
		num++;
	}
}