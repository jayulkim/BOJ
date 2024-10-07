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
	for (int i = 2; i * i < 1000001; i++)
	{
		if (ary[i] != 0)
		{
			for (int j = i * i; j < 1000001; j += i)
			{
				ary[j] = 0;
			}
		}
	}

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);

		int result1 = 0;
		int result2 = 0;
		for (int i = num2; i >= num2/ 2; i--)
		{
			if (ary[num2 - ary[i]] == num2 - ary[i])
			{
				result1++;
			}

		}
		printf("%d\n", result1);
	}


}
