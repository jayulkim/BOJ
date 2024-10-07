#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int num1 = 0;

	int num2 = 0;
	int count = 0;
	scanf("%d", &num1);

	
	
	num2 = (num1 % 10) * 10 + (((num1 / 10) + num1 % 10) % 10);
	count++;



	while (num2 != num1)
	{
		num2 = (num2 % 10) * 10 + (((num2 / 10) + num2 % 10) % 10);
		count++;
	}
	printf("%d", count);
}