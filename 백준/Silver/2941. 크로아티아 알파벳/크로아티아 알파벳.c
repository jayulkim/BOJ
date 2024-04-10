#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(void)
{
	char str1[1000];
	
	gets(str1);
	int num1 = strlen(str1);
	int count = 0;
	int num2 = strlen(str1);
	
	for (int i = 0; i < num1 - 2; i++)
	{
		if (str1[i] == 'd' && str1[i + 1] == 'z' && str1[i + 2] == '=')
		{
			num2 -= 2;
		}

	}
	if (num1 >= 3)
	{
		for (int i = 1; i < num1 - 1; i++)
		{
			if (str1[i] == 'z' && str1[i + 1] == '=' && str1[i - 1] != 'd')
			{
				num2 -= 1;
			}
		}
		if (str1[0] == 'z' && str1[1] == '=')
		{
			num2 -= 1;
		}
		for (int i = 0; i < num1 - 1; i++)
		{
			if (str1[i] == 'c' && str1[i + 1] == '=')
			{
				num2 -= 1;
			}
			else if (str1[i] == 'c' && str1[i + 1] == '-')
			{
				num2 -= 1;
			}
			else if (str1[i] == 'd' && str1[i + 1] == '-')
			{
				num2 -= 1;
			}
			else if (str1[i] == 'l' && str1[i + 1] == 'j')
			{
				num2 -= 1;
			}
			else if (str1[i] == 'n' && str1[i + 1] == 'j')
			{
				num2 -= 1;
			}
			else if (str1[i] == 's' && str1[i + 1] == '=')
			{
				num2 -= 1;
			}
			

		}
		printf("%d", num2);
	}
	else if (num1 == 2)
	{
		if (str1[0] == 'z' && str1[1] == '=')
		{

			num2 -= 1;
			printf("%d", num2);
		}
		else if (str1[0] == 'c' && str1[1] == '-')
		{
			num2 -= 1;
			printf("%d", num2);
		}
		else if (str1[0] == 'c' && str1[1] == '=')
		{
			num2 -= 1;
			printf("%d", num2);
		}
		else if (str1[0] == 'd' && str1[1] == '-')
		{
			num2 -= 1;
			printf("%d", num2);
		}
		else if (str1[0] == 'l' && str1[1] == 'j')
		{
			num2 -= 1;
			printf("%d", num2);
		}
		else if (str1[0] == 'n' && str1[1] == 'j')
		{
			num2 -= 1;
			printf("%d", num2);
		}
		else if (str1[0] == 's' && str1[1] == '=')
		{
			num2 -= 1;
			printf("%d", num2);
		}
		else if (str1[0] == 'z' && str1[1] == '=')
		{
			num2 -= 1;
			printf("%d", num2);
		}
		
		else
		{
			printf("%d", num2);

		}

	}
	else if (num1 == 1)
	{
		printf("1");
	}

	
}