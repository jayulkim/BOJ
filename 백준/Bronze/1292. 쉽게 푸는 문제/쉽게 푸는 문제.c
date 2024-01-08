#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int ary[1000] = { 0, };
	int result = 0;
	scanf("%d %d", &num1, &num2);

	for (int i = 1; i < 45; i++)
	{
		for (int j = (i * (i - 1) / 2); j <= (i * (i + 1) / 2); j++)
		{
			ary[j] = i;
		}
	}
	for (int i = 990; i < 1000; i++)
	{
		ary[i] = 45;
	}
	for (int i = num1 - 1; i < num2; i++)
	{
		result += ary[i];
	}
	printf("%d", result);
	
} 