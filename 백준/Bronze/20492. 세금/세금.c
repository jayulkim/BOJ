#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{

	long long int num1 = 0;


	scanf("%lld", &num1);
	printf("%lld %lld", num1 - (num1 * 22 / 100), num1 - (num1 * 20 / 100 * 22 / 100));


}