#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int ary[500005] = { 0, };

int main(void)
{
	char num1[1005];
	char str[10];
	char num2[1005];
	scanf("%s", num1);
	scanf("%s", str);
	scanf("%s", num2);

	int len1 = strlen(num1);
	int len2 = strlen(num2);

	if (strcmp(str, "+") == 0)
	{
		if (len1 > len2)
		{
			for (int i = 0; i <= len2; i++)
			{
				num1[len1 - len2 + i] = num2[i];
			}
			printf("%s", num1);
		}
		else if(len1 < len2)
		{
			for (int i = 0; i <= len2; i++)
			{
				num2[len2 - len1 + i] = num1[i];
			}
			printf("%s", num2);
		}
		else
		{
			num1[0] = '2';
			printf("%s", num1);
		}
	}
	else if (strcmp(str, "*") == 0)
	{
		if (len1 > len2)
		{
			for (int i = 1; i <= len2; i++)
			{
				num1[len1 + i - 1] = num2[i];
			}
			printf("%s", num1);
		}
		else
		{
			for (int i = 1; i <= len1; i++)
			{
				num2[len2 + i - 1] = num1[i];
			}
			printf("%s", num2);
		}
		
	}
	
}