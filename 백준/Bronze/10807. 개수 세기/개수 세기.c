#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[305] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		ary[num2 + 101]++;
	}
	int num3 = 0;
	scanf("%d", &num3);
	printf("%d", ary[num3 + 101]);
}