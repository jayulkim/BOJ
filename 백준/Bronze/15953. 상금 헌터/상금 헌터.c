#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[10] = { 0, 2, 4, 8, 16, 32 };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int result = 0;
		int num2 = 0;
		int num3 = 0;
		scanf("%d %d", &num2, &num3);
		int count = 1;
		while (count * (count + 1) / 2 < num2)
		{
			count++;
		}
		//printf("%d\n", count);
		if (count == 6)
		{
			result += 100000;
		}
		else if (count == 5)
		{
			result += 300000;
		}
		else if (count == 4)
		{
			result += 500000;
		}
		else if (count == 3)
		{
			result += 2000000;
		}
		else if (count == 2)
		{
			result += 3000000;
		}
		else if (count == 1 && num2 != 0)
		{
			result += 5000000;
		}
		
		int count1 = 1;
		int count2 = 1;
		if (count1 <= num3)
		{
			count1++;
			count2++;
		}
		if (count1 <= num3)
		{
			count1 += 2;
			count2++;
		}
		if (count1 <= num3)
		{
			count1 += 4;
			count2++;
		}
		if (count1 <= num3)
		{
			count1 += 8;
			count2++;
		}
		if (count1 <= num3)
		{
			count1 += 16;
			count2++;
		}
		count2--;
		if (num3 > 31)
		{
			count2 = 0;
		}
		if (count2 == 1)
		{
			result += 5120000;
		}
		else if (count2 == 2)
		{
			result += 2560000;
		}
		else if (count2 == 3)
		{
			result += 1280000;
		}
		else if (count2 == 4)
		{
			result += 640000;
		}
		else if (count2 == 5)
		{
			result += 320000;
		}
	//	printf("%d\n", count2);
		printf("%d\n", result);
	}

}