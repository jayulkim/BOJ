#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char str1[30];

	scanf("%s", str1);

	int num1 = strlen(str1);

	int result = 0;
	for (int i = 0; i < num1; i++)
	{
		if (islower(str1[i]) == 0)
		{
			result = result + str1[i] - 38;
		}
		else if (isupper(str1[i]) == 0)
		{
			result = result + str1[i] - 96;
		}
		
	}
	
	int count = 2;

	int count1 = 0;
	while (count * count <= result)
	{
		if (result % count == 0)
		{
			count1++;
		}
		count++;
	}
	if (count1 == 0)
	{
		printf("It is a prime word.");
	}
	else
	{
		printf("It is not a prime word.");
	}
	
}