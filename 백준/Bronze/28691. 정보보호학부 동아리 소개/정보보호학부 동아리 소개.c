#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(void)
{
	char num1;
	scanf("%c", &num1);
	if (num1 == 'M')
	{
		printf("MatKor\n");
	}
	else if (num1 == 'W')
	{
		printf("WiCys\n");
	}
	else if (num1 == 'C')
	{
		
		printf("CyKor\n");
	}
	else if (num1 == 'A')
	{

		printf("AlKor\n");
	}
	else if (num1 == '$')
	{

		printf("$clear\n");
	}
}