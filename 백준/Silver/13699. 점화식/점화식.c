#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long int ary[50] = { 1,};
long long int ary1[50] = { 1, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 1; i <= num1; i++)
	{
		long long  int sum = 0;
		for (int j = 0; j < i; j++)
		{
			sum += (ary[j] * ary[i - j - 1]);
			
		//	printf("%lld %lld\n", ary[j], ary[num1 - j - 1]);
		//	printf("%d %d\n", j, i - j - 1);
		}
		ary[i] = sum;
	//	printf("%lld\n", sum);

	}

	printf("%lld", ary[num1]);

}