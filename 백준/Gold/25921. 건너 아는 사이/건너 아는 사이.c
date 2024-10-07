#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[1000001] = { 0, };
int ary1[1000001] = { 0, };
int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	long long int result = 0;
	for (long long int i = 2; i <= num1; i++)
	{
		if (ary[i] == 0)
		{
			result += i;
			for (int j = i * 2; j <= num1; j += i)
			{
				if (ary1[j] == 0)
				{
					result += i;
					ary1[j] = 1;
				}
				ary[j] = 1;
			}
		}
	}
	printf("%lld\n", result);
}