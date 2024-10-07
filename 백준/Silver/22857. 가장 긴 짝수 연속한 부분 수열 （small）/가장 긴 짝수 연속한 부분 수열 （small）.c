#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[1000005] = { 0, };

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
	int count = 0;
	int max = 0;
	while (end < num1)
	{
		if (ary[end] % 2 == 1)
		{
			count++;
		}
		if (count > num2)
		{
			if (ary[start] % 2 == 1)
			{
				count--;
			}
			start++;
		}
		if (max < end - start - count + 1)
		{
			max = end - start - count + 1;
		}
		end++;
	}
	printf("%d", max);
}