#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[1000] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	int sum = 0;
	int count = 0;
	for (int i = 0; i < num1; i++)
	{
		if (ary[i] == 1)
		{
			count++;
			sum += count;
		}
		else
		{
			count = 0;
		}
	}
	printf("%d\n", sum);
}