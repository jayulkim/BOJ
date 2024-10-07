#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		int sum = 0;
		for (int j = 0; j < num2; j++)
		{
			int num3 = 0;
			scanf("%d", &num3);
			sum += num3;
		}
		printf("%d\n", sum);
	}
}