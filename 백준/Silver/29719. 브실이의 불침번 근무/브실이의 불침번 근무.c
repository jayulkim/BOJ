#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
long long int num3 = 1000000007;

int main(void)
{
	long long int num1 = 0;

	long long int num2 = 0;

	scanf("%lld %lld", &num1, &num2);

	long long int result1 = 1;

	long long int result2 = 1;

	

	for (long long int i = 0; i < num1; i++)
	{
		result1 *= num2;
		result2 *= num2 - 1;

		result1 = result1 % num3;
		result2 = result2 % num3;
	}
	printf("%lld\n", (result1 - result2 + num3) % num3);

}