#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[500005] = { 0, };

int main(void)
{
	int sum1 = 0;
	for (int i = 0; i < 4; i++)
	{
		int num1 = 0;
		scanf("%d", &num1);
		sum1 += num1;
	}
	int sum2 = 0;
	for (int i = 0; i < 4; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		sum2 += num2;
	}
	if (sum1 > sum2)
	{
		printf("%d", sum1);
	}
	else
	{
		printf("%d", sum2);
	}
}