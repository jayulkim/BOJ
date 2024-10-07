#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int num5 = 0;
	int num6 = 0;
	scanf("%d", &num5);
	long long int num1 = 0;
	long long int num2 = 0;
	long long  int num3 = 0;
	long long int num4 = 0;
	scanf("%lld %lld %lld %lld", &num1, &num2, &num3, &num4);

	if (num1 * num5 + num2 == num3 * num5 + num4)
	{
		printf("Yes %lld", num3 * num5 + num4);
	}
	else
	{
		printf("No");
	}
	
}