#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[10] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &ary[i]);
		ary[i] -= (num1 * num2);
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", ary[i]);
	}


}