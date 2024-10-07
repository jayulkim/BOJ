#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ary[10] = { 0, };

int main(void)
{
	int min = 101;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &ary[i]);
		if (min > ary[i])
		{
			min = ary[i];
		}
	}
	int count = min;
//	printf("%d\n", count);
	while (1)
	{
		int count1 = 0;
		
		
		for (int i = 0; i < 5; i++)
		{
			if (count % ary[i] == 0)
			{
				count1++;
			}
		}
		count++;
		if (count1 >= 3)
		{
			printf("%d\n", count - 1);
			break;
		}
	}
}
