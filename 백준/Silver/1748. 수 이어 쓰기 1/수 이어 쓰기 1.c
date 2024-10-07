#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

int ary[15] = { 9,90,900, 9000,90000,900000,9000000,90000000, 900000000 };
int ary1[15] = { 9, 99, 999, 9999, 99999 ,999999, 9999999, 99999999, 999999999 };


int main(void)
{
	char num1[15];
	scanf("%s", num1);

	int num2 = strlen(num1);

	long long sum = 0;
	for (int i = 0; i < num2 - 1; i++)
	{
		sum += ary[i] * (i + 1);
	}
	int num3 = atoi(num1);

	sum += (num3 - ary1[num2 - 2]) * num2;
	printf("%lld\n", sum);

}