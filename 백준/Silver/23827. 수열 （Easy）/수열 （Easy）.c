#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[500005] = { 0, };
long long int sum[500005] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}

	long long int result = 0;
	for (int i = 0; i < num1; i++)
	{
		sum[0] += ary[i];
	}
	for (int k = 1; k < num1; k++)
	{
		sum[k] = sum[k - 1] - ary[k - 1];
		result += sum[k] * ary[k - 1];
		result %= 1000000007;
	}
	printf("%lld\n", result % 1000000007);
	

}