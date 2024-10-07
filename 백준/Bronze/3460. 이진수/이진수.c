#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int num1 = 0; 

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int count = 0;

		scanf("%d", &num2);
		while (1)
		{
			if (num2 % 2 == 1)
			{
				printf("%d ", count);
			}
		

			count += 1;
			if (num2 / 2 < 1)
			{
				break;

			}
			num2 /= 2;
		}
		printf("\n");
	}
}