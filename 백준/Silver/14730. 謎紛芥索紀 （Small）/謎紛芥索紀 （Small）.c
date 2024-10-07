#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	long long int result = 0;
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		long long int num2 = 0;
		long long int num3 = 0;
		scanf("%lld %lld", &num2, &num3);

		result += num2 * num3;
	}
	printf("%lld\n", result);

}