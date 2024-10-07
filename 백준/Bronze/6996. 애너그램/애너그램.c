#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void* num1, const void* num2)
{
	char a = *(char*)num1;
	char b = *(char*)num2;

	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		char str1[105];
		char str2[105];
		scanf("%s %s", str1, str2);
		char str3[105];
		char str4[105];
		strcpy(str3, str1);
		strcpy(str4, str2);

		int num2 = strlen(str1);
		int num3 = strlen(str2);

		qsort(str1, num2, sizeof(char), compare);
		qsort(str2, num3, sizeof(char), compare);
		if (strcmp(str1, str2) == 0)
		{
			printf("%s & %s are anagrams.\n", str3, str4);
		}
		else
		{
			printf("%s & %s are NOT anagrams.\n", str3, str4);
		}

	}
	
}