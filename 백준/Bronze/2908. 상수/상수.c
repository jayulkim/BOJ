#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	char str1[300];
	char str2[300];

	char str3[300];
	char str4[300];

	scanf("%s %s", str1, str2);

	for (int i = strlen(str1) - 1; i >= 0; i--)
	{
		str3[strlen(str1) - i - 1] = str1[i];
	}
	for (int i = strlen(str2) - 1; i >= 0; i--)
	{
		str4[strlen(str2) - i - 1] = str2[i];
	}
	if (atoi(str3) > atoi(str4))
	{
		printf("%d", atoi(str3));
	}
	if (atoi(str3) < atoi(str4))
	{
		printf("%d", atoi(str4));
	}
}