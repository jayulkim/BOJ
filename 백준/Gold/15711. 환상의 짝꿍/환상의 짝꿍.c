#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[2000005] = { 0, };
long long int prime[200005] = { 0, };
void swap(long long int* num1, long long int* num2)
{
	long long int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main(void)
{
	for (int i = 2; i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = 2 * i; j <= 2000000; j+= i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (long long int i = 2; i <= 2000000; i++)
	{
		if (ary[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		long long int num2 = 0;
		long long int num3 = 0;
		int count = 0;
		scanf("%lld %lld", &num2, &num3);
		if (num2 > num3)
		{
			swap(&num2, &num3);
		}
		if (num3 + num2 == 0 || num3 + num2 == 1 || num3 + num2 == 2 || num3 + num2 == 3)
		{
			printf("NO\n");
		}
		else if (num3 + num2 > 3 && (num3 + num2) % 2 == 0)
		{
			printf("YES\n");
		}
		else if (num3 + num2 > 3 && (num3 + num2) % 2 == 1)
		{
			for (int i = 0; i < index; i++)
			{
				if ((num3 + num2 - 2) < prime[i] * prime[i])
				{
					break;
				}
				if ((num3 + num2 - 2) % prime[i] == 0)
				{
					if ((num3 + num2 - 2) / prime[i] == 1)
					{
						printf("YES\n");
						count++;
						break;
					}
					else
					{
						printf("NO\n");
						count++;
						break;
					}
				}
			}
			if (count == 0)
			{
				printf("YES\n");
			}
		}
	}
}