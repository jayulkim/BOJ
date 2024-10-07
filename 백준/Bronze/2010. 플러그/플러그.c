#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[500005] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	int sum = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		sum += ary[i];
		sum--;
	}
	sum++;
	printf("%d\n", sum);
}