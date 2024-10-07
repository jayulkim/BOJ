#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[105] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < 9; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		num1 -= num2;
	}
	printf("%d\n", num1);

}