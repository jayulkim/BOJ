#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[35] = { 0, };

int main(void)
{
	for (int i = 1; i <= 28; i++)
	{
		int num1 = 0;
		scanf("%d", &num1);
		ary[num1]++;
	}
	for (int i = 1; i <= 30; i++)
	{
		if (ary[i] == 0)
		{
			printf("%d\n", i);
		}
	}
}