#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(void)
{
	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);

	int count = 1;

	if (num1 < num2)
	{
		while (count <= num1 / 2)
		{
			if (num1 % count == 0 && num2 % count == 0)
			{
				printf("%d %d %d\n", count, num1 / count, num2 / count);
			}
			count++;
		}
		if (num2 % num1 == 0)
		{
			printf("%d %d %d\n", num1, 1, num2 / num1);
		}
	}
	else if (num1 >= num2)
	{
		while (count <= num2 / 2)
		{
			if (num1 % count == 0 && num2 % count == 0)
			{
				printf("%d %d %d\n", count, num1 / count, num2 / count);
			}
			count++;
		}
		if (num1 % num2 == 0)
		{
			printf("%d %d %d\n", num2, num2 / num1, 1);
		}
	}

	
	
	

}