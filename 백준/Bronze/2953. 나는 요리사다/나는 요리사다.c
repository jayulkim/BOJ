#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[105] = { 0, };

int main(void)
{
	int max = 0;
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int num1 = 0;
			scanf("%d", &num1);
			ary[i] += num1;
		}
		if (max < ary[i])
		{
			max = ary[i];
			index = i + 1;
		}
	}
	printf("%d %d", index, max);
	

}