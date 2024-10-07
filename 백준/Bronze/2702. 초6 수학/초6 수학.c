#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int num3 = 0;
		scanf("%d %d", &num2, &num3);

		

		if (num2 > num3)
		{
			int count = num3;
			while (count <= num3)
			{
				if (num2 % count == 0 && num3 % count == 0)
				{
					break;
				}
				count--;
			}
			printf("%d %d\n", num2 * num3 / count, count);
		}
		else
		{
			int count = num2;
			while (count <= num2)
			{
				if (num2 % count == 0 && num3 % count == 0)
				{
					break;
				}
				count--;
			}
			printf("%d %d\n", num2 * num3 / count, count);
		}
	}

}
