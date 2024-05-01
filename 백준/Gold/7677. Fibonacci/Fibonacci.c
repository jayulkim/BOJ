#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibonacci[15001] = { 0, };

int main(void)
{
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	for (int i = 2; i <= 15000; i++)
	{
		fibonacci[i] = (fibonacci[i - 1] % 10000) + (fibonacci[i - 2] % 10000);
		fibonacci[i] %= 10000;
	}
	while (1)
	{
		unsigned long long int n = 0;
		scanf("%llu", &n);
		if (n == -1)
		{
			break;
		}
		n %= 15000;
		printf("%d\n", fibonacci[n % 15000]);
	}
}