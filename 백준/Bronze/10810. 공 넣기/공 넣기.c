#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int num1 = 0; 
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	int ary[100] = { 0, };

	for (int i = 0; i < num2; i++)
	{
		int num3 = 0;
		int num4 = 0;
		int num5 = 0;
		scanf("%d %d %d", &num3, &num4, &num5);

		for (int j = num3 - 1; j < num4; j++)
		{
			ary[j] = num5;
		}
	}
	for (int i = 0; i < num1; i++)
	{
		printf("%d ", ary[i]);
	}
}

	