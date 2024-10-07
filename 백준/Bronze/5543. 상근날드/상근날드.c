#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[10] = { 0, };


int main(void)
{
	int min = 2001;
	int min1 = 2001;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &ary[i]);
		if (min > ary[i])
		{
			min = ary[i];
		}
	}
	for (int i = 3; i < 5; i++)
	{
		scanf("%d", &ary[i]);
		if (min1 > ary[i])
		{
			min1 = ary[i];
		}
	}
	printf("%d\n", min + min1 - 50);
}