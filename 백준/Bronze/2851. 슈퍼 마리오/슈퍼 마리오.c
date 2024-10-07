#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3[10] = { 0, };
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &num3[i]);
		if (result1 <= 100)
		{
			result1 += num3[i];
			result2 += 1;
		}
	}
	if (abs(100 - result1) < abs(100 - (result1 - num3[result2 -1])))
	{
		printf("%d", result1);
	}
	if (abs(100 - result1) > abs(100 - (result1 - num3[result2 -1])))
	{
		printf("%d", result1 - num3[result2 - 1]);
	}
	if (abs(100 - result1) == abs(100 - (result1 - num3[result2 - 1])))
	{
		if (result1 > result1 - num3[result2 - 1])
		{
			printf("%d", result1);
		}
		if (result1 < result1 - num3[result2 - 1])
		{
			printf("%d", result1 - num3[result2 - 1]);
		}
	}


}