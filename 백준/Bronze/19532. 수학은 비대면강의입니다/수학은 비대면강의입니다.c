#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int num5 = 0;
	int num6 = 0;
	int x = 0;
	int y = 0;
	scanf("%d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6);


	
	y = ((num3 * num4) - (num1 * num6)) / ((num4 * num2) - (num1 * num5));
	x = (num6 - (num5 * y)) / num4;



	printf("%d %d", x, y);
}

	