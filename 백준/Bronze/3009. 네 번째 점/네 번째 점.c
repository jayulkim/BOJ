#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(void)
{
	int num1 = 0; 
	int num2 = 0;

	int num3 = 0;
	int num4 = 0;

	int num5 = 0;
	int num6 = 0;

	int num7 = 0;
	int num8 = 0;

	scanf("%d %d", &num1, &num2);
	scanf("%d %d", &num3, &num4);
	scanf("%d %d", &num5, &num6);

	if (num1 == num3)
	{
		num7 = num5;
	}
	else if (num1 == num5)
	{
		num7 = num3;
	}
	else if (num3 == num5)
	{
		num7 = num1;
	}
	if (num2 == num4)
	{
		num8 = num6;
	}
	else if (num2 == num6)
	{
		num8 = num4;
	}
	else if (num4 == num6)
	{
		num8 = num2;
	}
	printf("%d %d", num7, num8);
}