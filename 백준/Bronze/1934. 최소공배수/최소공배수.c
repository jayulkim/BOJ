#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int num1 = 0; 
	
	
	scanf("%d", &num1);
	
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int num3 = 0;

		scanf("%d %d", &num2, &num3);
		if (num2 != 1 && num3 != 1)
		{
			if (num2 < num3)
			{
				int num4 = num2;
				while (num4 >= 1)
				{
					if (num2 % num4 == 0 && num3 % num4 == 0)
					{
				
						break;
					}
					num4--;
				}
				printf("%d\n", num2 * num3 / num4);
			}
			else if (num2 > num3)
			{
				int num4 = num3;
				while (num4 >= 1)
				{
					if (num2 % num4 == 0 && num3 % num4 == 0)
					{

						break;
					}
					num4--;
				}
				printf("%d\n", num2 * num3 / num4);
			}
			else
			{
				printf("%d\n", num2);
			}

		}
		else
		{
			printf("%d\n", num2 * num3);
		}
	}

}