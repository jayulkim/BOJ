#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[200] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);


	ary[1] = 1;
	ary[2] = 1;
	ary[3] = 1;

	for (int i = 4; i < 101; i++)
	{
		ary[i] = ary[i - 3] + ary[i - 2];
	}

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		printf("%lld\n", ary[num2]);


	}
}