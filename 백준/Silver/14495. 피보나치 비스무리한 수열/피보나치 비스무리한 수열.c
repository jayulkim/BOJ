#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int ary1[100000] = { 0, };

int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	ary1[0] = 0;
	ary1[1] = 1;
	ary1[2] = 1;

	for (int i = 3; i <= num1; i++)
	{
		ary1[i] = ary1[i - 1] + ary1[i - 3];
	}

	printf("%lld\n", ary1[num1]);
	
	

}
