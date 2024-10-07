#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

long long int ary[50001] = { 0, };
long long int sum[50001] = { 0, };

long long int mod[1000001] = { 0, };

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int j = 0; j < num; j++)
	{
		int num1 = 0;
		int num2 = 0;
		scanf("%d %d", &num1, &num2);
		long long int result = 0;
		for (int i = 0; i < num2; i++)
		{
			scanf("%lld", &ary[i]);
		}
		sum[0] = ary[0];
		for (int i = 1; i < num2; i++)
		{
			sum[i] = sum[i - 1] + ary[i];
		}
		for (int i = 0; i < num2; i++)
		{
			if (sum[i] % num1 == 0)
			{
				result++;
			}
			mod[sum[i] % num1]++;
		}
		for (int i = 0; i < num1; i++)
		{
			if (mod[i] != 0)
			{
				result += mod[i] * (mod[i] - 1) / 2;
			}
		}
		printf("%lld\n", result);
		memset(mod, 0, sizeof(mod));
	}
	
}