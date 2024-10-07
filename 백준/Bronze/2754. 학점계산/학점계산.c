#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	char str1[1000];

	scanf("%s", str1);

	if (str1[0] == 'A' && str1[1] == '+')
	{
		printf("4.3");
	}
	if (str1[0] == 'A' && str1[1] == '0')
	{
		printf("4.0");
	}
	if (str1[0] == 'A' && str1[1] == '-')
	{
		printf("3.7");
	}
	if (str1[0] == 'B' && str1[1] == '+')
	{
		printf("3.3");
	}
	if (str1[0] == 'B' && str1[1] == '0')
	{
		printf("3.0");
	}
	if (str1[0] == 'B' && str1[1] == '-')
	{
		printf("2.7");
	}
	if (str1[0] == 'C' && str1[1] == '+')
	{
		printf("2.3");
	}
	if (str1[0] == 'C' && str1[1] == '0')
	{
		printf("2.0");
	}
	if (str1[0] == 'C' && str1[1] == '-')
	{
		printf("1.7");
	}
	if (str1[0] == 'D' && str1[1] == '+')
	{
		printf("1.3");
	}
	if (str1[0] == 'D' && str1[1] == '0')
	{
		printf("1.0");
	}
	if (str1[0] == 'D' && str1[1] == '-')
	{
		printf("0.7");
	}
	if (str1[0] == 'F')
	{
		printf("0.0");
	}
}