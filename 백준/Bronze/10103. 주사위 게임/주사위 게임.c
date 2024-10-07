#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	int count = 100;
	int count1 = 100;
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int num3 = 0;
		scanf("%d %d", &num2, &num3);
		if (num2 > num3)
		{
			count -= num2;
		}
		else if (num3 > num2)
		{
			count1 -= num3;
		}

	}
	printf("%d\n%d", count1, count);
}