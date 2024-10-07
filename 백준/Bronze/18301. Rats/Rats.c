#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ary[5] = { 0, };

int compare(const void* num1, const void* num2)
{
	int a = *(int*)num1;
	int b = *(int*)num2;
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return -1;
	}
	else
	{
		return 0;
	}

}

char str[1000005];
char str1[1000005];
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	scanf("%d %d %d", &num1, &num2, &num3);
	printf("%d", (num1 + 1) * (num2 + 1) / (num3 + 1) - 1);
	

}