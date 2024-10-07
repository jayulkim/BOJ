#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[200005] = { 0, };

int ary1[100005] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}

	int start = 0;
	int end = 0;
	int max = 0;

	int count = 0;
	while (end < num1)
	{
		ary1[ary[end]]++;
		if (ary1[ary[end]] > num2)
		{
			while (ary1[ary[end]] > num2)
			{
				ary1[ary[start]]--;
				start++;
			}
			
		}
		else
		{
			if (max < end - start + 1)
			{
				max = end - start + 1;
			}
		}
		end++;
	}
	
	printf("%d\n", max);

}
