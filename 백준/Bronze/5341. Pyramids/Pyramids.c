#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	while (1)
	{
		int num1 = 0;
		int result = 0;

		scanf("%d", &num1);
		if (num1 == 0)
		{
			break;
		}
		for (int i = 1; i <= num1; i++)
		{
			result += i;
		}
		printf("%d\n", result);
	}
}