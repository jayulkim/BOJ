#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long int Pow(unsigned long long int A, unsigned long long int B, unsigned long long int C)
{
	unsigned long long int result = 1;
	A %= C;
	while (B > 0)
	{
		if (B % 2 == 1)
		{
			result *= (A % C);
			result %= C;
		}
		A *= (A %= C);
		A %= C;
		B /= 2;
	}
	return result;
}

int main(void)
{
	unsigned long long int A = 0;
	unsigned long long int B = 0;
	unsigned long long int C = 0;
	scanf("%llu %llu %llu", &A, &B, &C);
	printf("%llu", Pow(A, B, C));
}