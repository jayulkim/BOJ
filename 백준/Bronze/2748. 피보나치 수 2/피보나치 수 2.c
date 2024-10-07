#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)

{
	long long int num1 = 0;
	long long int ary[100] = { 0, };

	scanf("%lld", &num1);

	ary[0] = 0;
	ary[1] = 1;

	for (int i = 2; i < num1 + 1; i++)
	{
		ary[i] = ary[i - 1] + ary[i - 2];
	}
	printf("%lld\n", ary[num1]);

}