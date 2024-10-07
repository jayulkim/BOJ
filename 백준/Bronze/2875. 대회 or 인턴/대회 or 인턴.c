#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[500005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	scanf("%d %d %d", &num1, &num2, &num3);

	int count = 0;
	while (num1 >= 2 && num2 >= 1)
	{
		count++;
		num1 -= 2;
		num2 -= 1;
	}
	while (num3 > 0)
	{
		if (num1 < num3 && num2 < num3)
		{
			count--;
			num3 -= 3;
		}
		else
		{
			break;
		}
	}
	
	printf("%d\n", count);

}