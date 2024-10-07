#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	int count = 1;

	int result = 0;
	while (count < 501)
	{
		for (int i = count; i < 501; i++)
		{
			if (i * i - num1 == count * count)
			{
				result++;
			}
		}
		count++;
	}
	printf("%d", result);
}