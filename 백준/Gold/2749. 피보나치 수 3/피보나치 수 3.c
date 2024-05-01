#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibonacci[1500001] = { 0, };

int main(void)
{
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	unsigned long long int n = 0;
	scanf("%llu", &n);
	n %= 1500000;
	for (int i = 2; i <= 1500000; i++)
	{
		fibonacci[i] = (fibonacci[i - 1] % 1000000) + (fibonacci[i - 2] % 1000000);
		fibonacci[i] %= 1000000;
	}
	printf("%d", fibonacci[n % 1500000]);
}