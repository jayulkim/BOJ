#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	if (num1 == 4 || num1 == 7)
	{
		printf("-1");
	}
	
	else if (num1 % 5 == 3)
	{
		printf("%d", (num1 / 5) + 1);
	}
	else if (num1 % 5 == 4)
	{
		printf("%d", ((num1 / 5) - 1) + 3);
	}
	else if (num1 % 5 == 0)
	{
		printf("%d", num1 / 5);
	}
	else if (num1 % 5 == 1)
	{
		printf("%d", ((num1 / 5) - 1) + 2);
	}
	else if (num1 % 5 == 2)
	{
		printf("%d", ((num1 / 5) - 2) + 4);
	}
}