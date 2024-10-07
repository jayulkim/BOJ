#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[50] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		int num2 = 10;
		int num3 = ary[i];
		while (num3 >= 30)
		{
			num2 += 10;
			num3 -= 30;
		}
		sum1 += num2;
		int num4 = 15;
		int num5 = ary[i];
		while (num5 >= 60)
		{
			num4 += 15;
			num5 -= 60;
		}
		sum2 += num4;
	}
	if (sum1 > sum2)
	{
		printf("M %d", sum2);
	}
	else if (sum1 < sum2)
	{
		printf("Y %d", sum1);
	}
	else
	{
		printf("Y M %d", sum1);
	}

}