#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str1[500];

int main(void)
{
	
	while (1)
	{
		
		int count = 0;
		gets(str1);
		if (strcmp(str1, "#") == 0)
		{
			break;
		}
		for (int i = 1; i < strlen(str1); i++)
		{
			if (str1[i] == str1[0] || str1[i] == toupper(str1[0]))
			{
				count += 1;
			}
		}
		printf("%c %d\n", str1[0], count);

		
	}

}