#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	int num1 = 0;
	int result = 0;
	for (int i = 0; i < 5; i++)
	{
		
		scanf("%d", &num1);
		result += num1;
	}
	printf("%d", result);
}