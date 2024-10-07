#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	if (num1 == 2)
	{
		int num2 = 0;
		int num3 = 0;

		scanf("%d %d", &num2, &num3);
		
		int count = 1;
		if (num2 > num3)
		{
			while (count <= num3 / 2)
			{
				if (num3 % count == 0 && num2 % count == 0)
				{
					printf("%d\n", count);
				}
				count++;
			}
			if (num2 % num3 == 0)
			{
				printf("%d\n", num3);
			}
		}
		else
		{
			while (count <= num2 / 2)
			{
				if (num3 % count == 0 && num2 % count == 0)
				{
					printf("%d\n", count);
				}
				count++;
			}
			if (num3 % num2 == 0)
			{
				printf("%d\n", num2);
			}
		}
	}
	if (num1 == 3)
	{
		int num4 = 0;
		int num5 = 0;
		int num6 = 0;
		int min = 1000000000;
		scanf("%d %d %d", &num4, &num5, &num6);
		
		int count1 = 1;
		if (min > num4)
		{
			min = num4;
		}
		if (min > num5)
		{
			min = num5;
		}
		if (min > num6)
		{
			min = num6;
		}
		while (count1 <= min / 2)
		{
			if (num4 % count1 == 0 && num5 % count1 == 0 && num6 % count1 == 0)
			{
				printf("%d\n", count1);
			}
			count1++;
		}
		if (num4 % min == 0 && num5 % min == 0 && num6 % min == 0)
		{
			printf("%d\n", min);
		}
	}
}
