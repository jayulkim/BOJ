#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	char str1[10000];
	char str2[10000];

	gets(str1);
	gets(str2);

	if (strlen(str1) >= strlen(str2))
	{
		printf("go");
	}
	else if (strlen(str1) < strlen(str2))
	{
		printf("no");
	}
	
}