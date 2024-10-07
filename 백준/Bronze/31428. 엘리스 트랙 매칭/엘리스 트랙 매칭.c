#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100005] = { 0, };

char str1[5];

int main(void)
{
	char num2[10];
	gets(num2);

	int num1 = atoi(num2);
	int count = 0;

	gets(str);
	int num3 = strlen(str);
	//printf("%c", str[1]);
	gets(str1);

	for (int i = 0; i <= num3; i++)
	{
		if (str[i] == str1[0])
		{
			count++;
		}
	}

	printf("%d\n", count);


}