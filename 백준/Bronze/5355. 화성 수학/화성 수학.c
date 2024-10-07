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
		double num2 = 0;
		char str[10];
		scanf("%lf", &num2);
		gets(str);

		int num3 = strlen(str);
		for (int j = 0; j < num3; j++)
		{
			if (str[j] == '@')
			{
				num2 *= 3;
			}
			else if (str[j] == '%')
			{
				num2 += 5;
			}
			else if (str[j] == '#')
			{
				num2 -= 7;
			}
		}
		printf("%.2lf\n", num2);
		
	}

	

}
