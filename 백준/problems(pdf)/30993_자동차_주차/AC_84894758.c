#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

	long long int count = 1;
	long long int count1 = 1;
	long long int count2 = 1;
	long long int count3 = 1;

	for (int i = 2; i <= num1; i++)
	{
		count *= i;
	}
	for (int i = 2; i <= num2; i++)
	{
		count1 *= i;
	}
	for (int i = 2; i <= num3; i++)
	{
		count2 *= i;
	}
	for (int i = 2; i <= num4; i++)
	{
		count3 *= i;
	}
	printf("%lld\n", count / (count1 * count2 * count3));
}