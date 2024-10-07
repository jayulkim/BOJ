#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	char str1[300];
	while (1)
	{
		int count = 0;
		gets(str1);
		if (str1[0] == '#')
		{
			break;
		}
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] == 'a')
			{
				count += 1;
			}
			if (str1[i] == 'e')
			{
				count += 1;
			}
			if (str1[i] == 'i')
			{
				count += 1;
			}
			if (str1[i] == 'o')
			{
				count += 1;
			}
			if (str1[i] == 'u')
			{
				count += 1;
			}
			if (str1[i] == 'A')
			{
				count += 1;
			}
			if (str1[i] == 'E')
			{
				count += 1;
			}
			if (str1[i] == 'I')
			{
				count += 1;
			}
			if (str1[i] == 'O')
			{
				count += 1;
			}
			if (str1[i] == 'U')
			{
				count += 1;
			}
		}
		printf("%d\n", count);
	}

}