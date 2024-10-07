#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[105] = { 0, };

int main(void)
{
	ary[1] = 2;
	ary[2] = 4;
	ary[3] = 7;
	ary[4] = 10;
	int count = 4;
	for (int i = 5; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			ary[i] = ary[i - 1] + count;
		}
		else
		{
			ary[i] = ary[i - 1] + count;
			count++;
		}
	}
	int num1 = 0;
	scanf("%d", &num1);
	printf("%d\n", ary[num1]);
}