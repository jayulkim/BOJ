#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	long long int num1 = 0;
	long long int num2 = 0;
	long long int num3 = 0;

	scanf("%lld %lld", &num1, &num2);
	scanf("%lld", &num3);
	
	if (num1 + num2 <2 * num3)
	{
		printf("%d", num1 + num2);
	}
	else if (num1 + num2 >= 2 *num3)
	{
		printf("%d", num1 + num2 - 2 * num3);
	}
}