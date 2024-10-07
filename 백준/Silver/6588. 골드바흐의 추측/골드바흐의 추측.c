#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[1000001] = { 0, };

int main(void)
{
	int num1 = 0;
	for (int i = 2; i < 1000001; i++)
	{
		ary[i] = i;

	}
	for (int i = 2; i < 1000001; i++)
	{
		if (ary[i] != 0)
		{
			for (int j = i * 2; j < 1000001; j += i)
			{
				ary[j] = 0;
			}
		}
	}

	while (1)
	{
		int num2 = 0;
		scanf("%d", &num2);
		if (num2 == 0)
		{
			break;
		}


		int result1 = 0;
		int result2 = 0;
		for (int i = num2; i >= 0; i--)
		{
			if (ary[num2 - ary[i]] != 0)
			{
				result1 = ary[i];
				result2 = num2 - ary[i];
				break;
			}
		}
		if (result1 != 0 && result2 != 0 && (result1 > result2))
		{
			printf("%d = %d + %d\n", result1 + result2, result2, result1);
		}
		else if (result1 != 0 && result2 != 0 && (result1 <= result2))
		{
			printf("%d = %d + %d\n", result1 + result2, result1, result2);
		}
	}


}
