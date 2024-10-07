#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{

	long long int num1 = 0;
	long long int num2 = 0;

	scanf("%lld %lld", &num1, &num2);

	printf("%lld", (num1 + num2) * (num1 - num2));


}