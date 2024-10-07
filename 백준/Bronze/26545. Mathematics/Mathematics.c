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
	scanf("%d", &num1);
	int sum = 0;
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		sum += num2;
	}
	printf("%d", sum);
}