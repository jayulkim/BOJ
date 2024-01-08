#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str1[5][15] = { 0, };
	for (int i = 0; i < 5; i++)
	{
		
		gets(str1[i]);
		
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (str1[j][i] != NULL)
			{
				printf("%c", str1[j][i]);
			}
		
		}

	}
}