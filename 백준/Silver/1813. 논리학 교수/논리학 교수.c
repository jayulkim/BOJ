#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

int ary[60] = { 0, };
int Index[60] = { 0, };

int ary1[60] = { 0, };
int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);

		Index[ary[i]]++;
	}
	int max = 0;
	int count = 0;

	int index = 0;
	for (int i = num1; i >= 0; i--)
	{
		if (ary[i] == Index[ary[i]])
		{
			//printf("%d\n", ary[i]);
			ary1[index] = ary[i];
			index++;
		}

	}
	if (index == 0)
	{
		printf("-1\n");
	}
	else
	{
		int max = 0;
		for (int i = 0; i < index; i++)
		{
			if (max < ary1[i])
			{
				max = ary1[i];
			}
		}
		printf("%d\n", max);
	}
}