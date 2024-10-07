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

	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &num3);

	if (num1 == 60 && num2 == 60 && num3 == 60)
	{
		printf("Equilateral");
	}
	if (num1 + num2 + num3 == 180 && num1 == num2 && num1 != num3)
	{
		printf("Isosceles");
	}
	if (num1 + num2 + num3 == 180 && num1 == num3 && num1 != num2)
	{
		printf("Isosceles");
	}
	if (num1 + num2 + num3 == 180 && num2 == num3 && num2 != num1)
	{
		printf("Isosceles");
	}
	if (num1 + num2 + num3 == 180 && num1 != num2 && num2 != num3 && num1 != num3)
	{
		printf("Scalene");
	}
	if (num1 + num2 + num3 != 180)
	{
		printf("Error");
	}
}