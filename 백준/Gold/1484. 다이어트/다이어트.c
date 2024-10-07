#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

long long int ary[100005] = { 0, };

int main(void)
{
//	printf("%lld\n", 100000LL * 100000LL);
	int num1 = 0;
	scanf("%d", &num1);
	for (long long int i = 0; i < num1; i++)
	{
		ary[i] = (i+1) * (i+1);
		//printf("%lld\n", ary[i]);
	}

	int start = 0;
	int end = 0;

	if (num1 == 1)
	{
		printf("-1\n");
		return 0;
	}
	int count = 0;
	while (start < num1)
	{
		if (start == end)
		{
			end++;
		}
		if (ary[end] - ary[start] < num1)
		{
			end++;
		}
		else if (ary[end] - ary[start] > num1)
		{
			start++;
		}
		else
		{
			count++;
			printf("%lld\n", ary[end] / (end + 1));
			start++;
			end++;
		}
		
	}
	if (count == 0)
	{
		printf("-1\n");
	}

}