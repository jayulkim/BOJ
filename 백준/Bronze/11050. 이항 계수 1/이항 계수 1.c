#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)

{
	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);
	
	int count1 = 1;
	for (int i = 0; i < num2; i++)
	{
		count1 *= num1 - i;
	}
	int count2 = 1;

	for (int i = 1; i <= num2; i++)
	{
		count2 *= i;
	}
	printf("%d\n", count1 / count2);
}
