#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[10005] = { 0, };

int main(void)
{
	for (int i = 1; i <= 10000; i++)
	{
		ary[i + i % 10 + (i / 10) % 10 + (i / 100) % 10 + (i / 1000) % 10] = 1;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (ary[i] == 0)
		{
			printf("%d\n", i);
		}
	}
}
