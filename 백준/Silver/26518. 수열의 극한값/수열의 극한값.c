#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	long double num1 = 0;
	long double num2 = 0;
	long double num3 = 0;
	long double num4 = 0; 

	scanf("%Lf %Lf %Lf %Lf", &num1, &num2, &num3, &num4);

	double num5 = sqrt(num1 * num1 + 4 * num2);
	printf("%.1000Lf", (num1 + num5) / 2);

}