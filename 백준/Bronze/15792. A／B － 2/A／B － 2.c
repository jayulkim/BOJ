#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	int num3 = num1 / num2;
    
	


	int num4 = num1 % num2;
	if (num4 == 0)
	{
		printf("%d", num3);
	}
	else
	{
		
		printf("%d.", num3);

		for (int i = 0; i < 2000; i++)
		{
			if (num4 % num2 == 0)
			{
				break;
			}
			while (num4 < num2)
			{
				num4 *= 10;
				printf("%d", num4 / num2);
			}
			
			
			num4 %= num2;
			

		}
	}
	
}