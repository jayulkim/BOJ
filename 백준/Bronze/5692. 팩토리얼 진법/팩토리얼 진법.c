#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	while (1)
	{
		
		int result = 0;

		char str1[10];
		int ary1[10] = { 0, };

		scanf("%s", str1);
		if (str1[0] == '0')
		{
			break;
		}
		for (int i = 1; i <= strlen(str1); i++)
		{
			int num1 = 1;
			int num2 = 0;
			if (str1[i - 1] == '1')
			{
				for (int j = 1; j <= strlen(str1) - i + 1; j++)
				{
					num1 *= j;
				}
				
				ary1[i - 1] = num1 * 1;
			}
			if (str1[i - 1] == '2')
			{
				for (int j = 1; j <= strlen(str1) - i + 1; j++)
				{
					num1 *= j;
				}
				ary1[i - 1] = num1 * 2;
			}
			if (str1[i - 1] == '3')
			{
				for (int j = 1; j <= strlen(str1) - i + 1; j++)
				{
					num1 *= j;
				}
				ary1[i - 1] = num1 * 3;
			}
			if (str1[i - 1] == '4')
			{
				for (int j = 1; j <= strlen(str1) - i + 1; j++)
				{
					num1 *= j;
				}
				ary1[i - 1] = num1 * 4;
			}
			if (str1[i - 1] == '5')
			{
				for (int j = 1; j <= strlen(str1) - i + 1; j++)
				{
					num1 *= j;
				}
				ary1[i - 1] = num1 * 5;
			}
			if (str1[i - 1] == '6')
			{
				for (int j = 1; j <= strlen(str1) - i + 1; j++)
				{
					num1 *= j;
				}
				ary1[i - 1] = num1 * 6;
			}
			if (str1[i - 1] == '7')
			{
				for (int j = 1; j <= strlen(str1) - i + 1; j++)
				{
					num1 *= j;
				}
				ary1[i - 1] = num1 * 7;
			}
			if (str1[i - 1] == '8')
			{
				for (int j = 1; j <= strlen(str1) - i + 1; j++)
				{
					num1 *= j;
				}
				ary1[i - 1] = num1 * 8;
			}
			if (str1[i - 1] == '9')
			{
				for (int j = 1; j <= strlen(str1) - i + 1; j++)
				{
					num1 *= j;
				}
				ary1[i - 1] = num1 * 9;
			}
			if (str1[i - 1] == '0')
			{
				for (int j = 1; j <= strlen(str1) - i + 1; j++)
				{
					num1 *= j;
				}
				ary1[i - 1] = num1 * 0;
			}
		}
		for (int i = 0; i < strlen(str1); i++)
		{
			result += ary1[i];
		}
		printf("%d\n", result);
		
	}
}