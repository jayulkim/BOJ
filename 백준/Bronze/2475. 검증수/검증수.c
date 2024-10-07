#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	int result = 0;
	int ary1[10] = { 0, };

	for (int i = 0; i < 5; i++)
	{

		int num1 = 0;
		scanf("%d", &num1);

		ary1[i] = num1 * num1;
	}
	for (int i = 0; i < 5; i++)
	{
		result += ary1[i];
	}
	printf("%d", result % 10);


   
}