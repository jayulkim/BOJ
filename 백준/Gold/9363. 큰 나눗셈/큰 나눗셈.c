#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[1001] = { 0, };
int prime[501] = { 0, };

int up[1000001] = { 0, };
int down[1000001] = { 0, };

int main(void)
{
	for (int i = 2; i * i <= 1000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 1000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (int i = 2; i <= 1000; i++)
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
		int sizeup = 0;
		int sizedown = 0;
		scanf("%d %d", &sizeup, &sizedown);
		
		for (int j = 0; j < sizeup; j++)
		{
			int index1 = 0;
			int num2 = 0;
			scanf("%d", &num2);
			while (num2 > 1)
			{
				if (num2 % prime[index1] == 0)
				{
					up[prime[index1]]++;
					num2 /= prime[index1];
				}
				else
				{
					index1++;
				}
				if (prime[index1] == 0)
				{
					up[num2]++;
					break;
				}
			}
		}
		
		for (int j = 0; j < sizedown; j++)
		{
			int index2 = 0;
			int num3 = 0;
			scanf("%d", &num3);
			while (num3 > 1)
			{
				if (num3 % prime[index2] == 0)
				{
					down[prime[index2]]++;
					num3 /= prime[index2];
				}
				else
				{
					index2++;
				}
				if (prime[index2] == 0)
				{
					down[num3]++;
					break;
				}
			}
		}
		int result1 = 1;
		int result2 = 1;
		for (int j = 2; j <= 1000000; j++)
		{
			if (up[j] != 0 || down[j] != 0)
			{
				if (up[j] > down[j])
				{
					for (int k = 0; k < up[j] - down[j]; k++)
					{
						result1 *= j;
					}
				}
				else if (up[j] < down[j])
				{
					for (int k = 0; k < down[j] - up[j]; k++)
					{
						result2 *= j;
					}
				}
			}
		}
		printf("Case #%d: %d / %d\n",i + 1, result1, result2);
		memset(up, 0, sizeof(up));
		memset(down, 0, sizeof(down));
	}
}
