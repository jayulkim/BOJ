#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[500005] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	int num2 = 0;
	scanf("%d", &num2);
	int num3 = 0;
	scanf("%d", &num3);
	int num4 = 0;
	scanf("%d", &num4);
	int num5 = 0;
	scanf("%d", &num5);

	int num6 = num2 / num4;
	if (num2 % num4 != 0)
	{
		num6++;
	}
	
	int num7 = num3 / num5;
	if (num3 % num5 != 0)
	{
		num7++;
	}
	if (num7 > num6)
	{
		printf("%d", num1 - num7);
	}
	else
	{
		printf("%d", num1 - num6);
	}
	
}