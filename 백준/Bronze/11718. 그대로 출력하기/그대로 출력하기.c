#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	char str1[1000];

	while(1)
	{
		if (gets(str1) == NULL)
		{
			break;
		}

		puts(str1);


	}
}