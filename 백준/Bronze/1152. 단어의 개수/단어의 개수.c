#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	
	
	char str1[1000000];
	int count = 0;



	
	gets(str1);
	int num3 = strlen(str1);
	for (int i = 0; i < num3; i++)
	{
		if (str1[i] == ' ')
		{
			count += 1;
		}
	}
	if (str1[0] == ' ' && str1[strlen(str1) - 1] != ' ')
	{
		printf("%d", count);
	}
	if (str1[0] == ' ' && str1[strlen(str1) - 1] == ' ')
	{

		printf("%d", count - 1);

	}
	if (str1[0] != ' ' && str1[strlen(str1) - 1] == ' ')
	{
		printf("%d", count);
	}
	if (str1[0] != ' ' && str1[strlen(str1) - 1] != ' ')
	{
		printf("%d", count + 1);
	}
	

}