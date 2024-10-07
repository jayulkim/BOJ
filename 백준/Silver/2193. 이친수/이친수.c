#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long int ary[100] = { 1,1, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 2; i < num1; i++)
	{
		ary[i] = ary[i - 1] + ary[i - 2];
	}

	printf("%lld\n", ary[num1 - 1]);

}
