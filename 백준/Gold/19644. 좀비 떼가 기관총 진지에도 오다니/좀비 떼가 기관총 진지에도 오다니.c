#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[3000005] = { 0, };
long long int sum[3000005] = { 0, };

int main(void)
{
	long long int num1 = 0;
	scanf("%lld", &num1);
	long long int num2 = 0;
	long long int num3 = 0;
	scanf("%lld %lld", &num2, &num3);
	long long int num4 = 0;
	scanf("%lld", &num4);
	long long int count = 0;
	sum[0] = 0;
	for (long long int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
	}
	for (long long int i = 0; i < num1; i++)
	{
		//printf("%d\n", count);
		if (i + 1 < num2)
		{
			sum[i + 1] = sum[i];
			if (sum[i+1] + num3 >= ary[i])
			{
				sum[i + 1] += num3;
			}
			else
			{
				if (num4 == 0)
				{
					printf("NO");
					return 0;
				}
				num4--;
			}
		}
		else
		{
			sum[i + 1] = sum[i];
			if (num3 + sum[i] - sum[i - num2 + 1] >= ary[i])
			{
				sum[i + 1] += num3;
			}
			else
			{
				if (num4 == 0)
				{
					printf("NO");
					return 0;
				}
				num4--;
			}
		}
		
	}
	printf("YES");
}
