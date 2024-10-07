#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[10] = { 0, 2, 4, 8, 16, 32 };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		int num3 = 0;
		scanf("%d", &num3);
		for (int j = 0; j < num3; j++)
		{
			int num4 = 0;
			int num5 = 0;
			scanf("%d %d", &num4, &num5);
			num2 += (num4 * num5);
		}
		printf("%d\n", num2);
	}

}