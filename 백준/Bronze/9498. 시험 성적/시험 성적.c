#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	if (num1 < 101 && num1 > 89)
	{
		printf("A");
	}
	if (num1 < 90 && num1 > 79)
	{
		printf("B");
	}
	if (num1 < 80 && num1 > 69)
	{
		printf("C");

	}
	if (num1 < 70 && num1 > 59)
	{
		printf("D");
	}
	if (num1 < 60)
	{
		printf("F");
	}

}