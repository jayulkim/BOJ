#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct info
{
	int pos;
	int number;
}info;

info list[10];

int main(void)
{
	long long int result = 1;
	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);

	int num3 = 0;
	int num4 = 0;

	scanf("%d %d", &num3, &num4);

	int count = 0;
	int count1 = 0;
	int max = 9;
	for (int i = 0; i < num2; i++)
	{
		scanf("%d %d", &list[i].pos, &list[i].number);
		if (list[i].pos == 0)
		{
			count++;
		}
		else
		{
			count1++;
		}
	}
	for (int i = 0; i < num1 - num2; i++)
	{
		result *= max - i - num2;
	}

	for (int i = 2; i <= num1 - count1; i++)
	{
		result *= i;
	}

	for (int i = num1 - num2; i >= 2; i--)
	{
		result /= i;
	}

	if (result % 3 == 0)
	{
		printf("%d\n", result * num3 + (result / 3) * num4 - num4);
	}
	else
	{
		printf("%d\n", result * num3 + (result / 3) * num4);
	}



}
