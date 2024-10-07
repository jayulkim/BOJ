#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{

	int num1 = 0;


	scanf("%d", &num1);

	if (num1 % 5 != 0)
	{
		printf("%d", num1 / 5 + 1);

	}
	else if (num1 % 5 == 0)
	{
		printf("%d", num1 / 5);
	}


}