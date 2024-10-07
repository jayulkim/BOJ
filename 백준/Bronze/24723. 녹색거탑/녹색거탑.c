#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[10] = { 0, 2, 4, 8, 16, 32 };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	printf("%d\n", ary[num1]);
}