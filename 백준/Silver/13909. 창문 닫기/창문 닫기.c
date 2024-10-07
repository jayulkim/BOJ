#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
	long long int num1 = 0;

	scanf("%lld", &num1);

	long long int count = 0;


	while (count * count <= num1)
	{
		count++;
	}
	printf("%lld\n", count - 1);

}