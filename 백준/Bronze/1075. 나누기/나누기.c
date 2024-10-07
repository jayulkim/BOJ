#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num1 = 0;

	int num2 = 0;

	scanf("%d", &num1);
	scanf("%d", &num2);
	int num3 = (num1 / 100) * 100;

	while (1)
	{
		if (num3 % num2 == 0)
		{
			break;
		}
		else if (num3 % num2 != 0)
		{
			num3++																		;
		}
	}
	if (num3 % 100 < 10)
	{
		printf("0%d\n", num3 % 100);
	}
	else
	{
		printf("%d\n", num3 % 100);
	}

}
