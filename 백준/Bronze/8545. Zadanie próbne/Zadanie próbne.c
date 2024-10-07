#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
char str[10];
int main(void)
{
	scanf("%s", str);
	int num1 = strlen(str);
	for (int i = num1 - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}

}