#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	while (scanf("%d %d", &num1, &num2) != EOF)
	{
		printf("%d\n", num2 / (num1 + 1));
	}
}