#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ary[100005] = { 0, };
int ary1[1000005] = { 0, };
int result[1000005] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	int max = 0;

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &ary[i]);
		if (ary[i] > max)
		{
			max = ary[i];
		}
		ary1[ary[i]] = 1;
	}
	for (int i = 0; i <= max; i++)
	{
		//printf("%d ", ary1[i]);
	}
	//printf("\n");
	for (int i = 0; i < num1; i++)
	{
		for (int j = ary[i] * 2; j <= max; j += ary[i])
		{
			if (ary1[j] != 0)
			{
				result[ary[i]]++;
				result[j]--;
			}
		}
	}
	for (int i = 0; i < num1; i++)
	{
		printf("%d ", result[ary[i]]);
	}
	for (int i = 0; i <= max; i++)
	{
		//printf("%d ", result[i]);
	}

}