#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	char str1[1000];

	scanf("%s", str1);

	for (int i = 0; i < strlen(str1); i++)
	{
		if (islower(str1[i]))
		{
			str1[i] = toupper(str1[i]);
		}
		else if (isupper(str1[i]))
		{
			str1[i] = tolower(str1[i]);
		}

	}
	printf("%s", str1);

   
}