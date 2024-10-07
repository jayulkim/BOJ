#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[100005] = { 0, };

int ary1[100005] = { 0, };

int main(void)
{
	long long int num1 = 0;

	scanf("%lld", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}

	long long int start = 0;
	long long int end = 1;

	long long int count = num1 * (num1 + 1) / 2;

	ary1[ary[start]]++;
	while (end < num1)
	{
		
		if (ary1[ary[end]] == 1)
		{
			ary1[ary[start]]--;
			start++;
			count -= (num1 - end);
			//3
			// 3
			// 2
			// 
			//	memset(ary1, 0, sizeof(ary1));
		}
		else
		{
			ary1[ary[end]]++;
			end++;
		}
		if (end == num1)
		{
			//start++;
			//end1 = end;
			
			//memset(ary1, 0, sizeof(ary1));
		}
	}

	printf("%lld\n", count);

}