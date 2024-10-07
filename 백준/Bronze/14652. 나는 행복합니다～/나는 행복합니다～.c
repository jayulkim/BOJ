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

	scanf("%d %d %d", &num1, &num2, &num3);
	printf("%d %d", num3 / num2, num3 % num2);


}