#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	int sum = 0;
	int count = 0;
	for (int i = 1; i <= 9999; i++)
	{
		if (sum + i <= num1)
		{
			sum += i;
			//printf("%d\n", i);
		}
		else
		{
			count = i;
			break;
		}
		
	}
	if (count % 2 == 1)
	{
		
		printf("%d\n", count - num1 + sum);
		
		
	}
	else
	{
		printf("0\n");
	}
}