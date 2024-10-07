#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	scanf("%d %d %d", &num1, &num2, &num3);
	if (num1 + num2 == num3)
	{
		printf("correct!\n");
	}
	else
	{
		printf("wrong!\n");
	}
}
