#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
	int num2 = 1;
	while (1)
	{
		int num1 = 0;

		scanf("%d", &num1);
		if (num1 == 0)
		{
			break;
		}
		else
		{

	
			int count= 0;
			for (int i = 2; i <= num1; i++)
			{

				int num3 = i;
				int num4 = i;

				while (1)
				{
					if (num4 % 5 == 0)
					{
						count++;
						num4 /= 5;
					}
					else
					{
						break;
					}
				}
			}
			
			
			printf("Case #%d: %d\n", num2, count);
			num2++;
			
		}

	}
	
	

	
	
}
