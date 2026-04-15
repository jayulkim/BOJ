#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int ary[10] = { 0, };

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


char str[25];
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	scanf("%d %d %d", &num1, &num2, &num3);

	int num4 = 0;
	int num5 = 0;
	int num6 = 0;
	scanf("%d %d %d", &num4, &num5, &num6);

	if (120 * num3 + 20 * num2 + 3 * num1 > 120 * num6 + 20 * num5 + 3 * num4)
	{
		printf("Max");
	}
	else if (120 * num3 + 20 * num2 + 3 * num1 < 120 * num6 + 20 * num5 + 3 * num4)
	{
		printf("Mel");
	}
	else
	{
		printf("Draw");
	}
	
}