#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int ary[1000005] = { 0, };

long long int ary1[1000005] = { 0, };




int main(void)
{
	for (int i = 1; i <= 1000000; i++)
	{
		for (int j = i; j <= 1000000; j += i)
		{
			ary[j]+= i;
		}
	}
	ary1[1] = ary[1];
	for (int i = 2; i <= 1000000; i++)
	{
		ary1[i] = ary1[i - 1] + ary[i];
	}

	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);

		printf("%lld\n", ary1[num2]);

	}

}
