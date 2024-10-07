#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char num1[10];
char num2[10];

int main(void)
{
	scanf("%s %s", num1, num2);
	int len1 = strlen(num1);
	int len2 = strlen(num2);

	for (int i = 0; i <= len1; i++)
	{
		if (num1[i] == '6')
		{
			num1[i] = '5';
		}
	}
	for (int i = 0; i <= len2; i++)
	{
		if (num2[i] == '6')
		{
			num2[i] = '5';
		}
	}
	int num3 = atoi(num1);
	int num4 = atoi(num2);
	printf("%d ", num3 + num4);
	for (int i = 0; i <= len1; i++)
	{
		if (num1[i] == '5')
		{
			num1[i] = '6';
		}
	}
	for (int i = 0; i <= len2; i++)
	{
		if (num2[i] == '5')
		{
			num2[i] = '6';
		}
	}
	int num5 = atoi(num1);
	int num6 = atoi(num2);
	printf("%d", num5 + num6);
}