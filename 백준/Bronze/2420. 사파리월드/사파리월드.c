#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	long long int num1 = 0;
	long long int num2 = 0;

	scanf("%lld %lld", &num1, &num2);

	printf("%lld", llabs(num1 - num2));
	
}
