#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[60];
char str1[60];

int ary[60] = { 0, };

int main(void)
{
	scanf("%s %s", str, str1);

	int num1 = strlen(str);
	int num2 = strlen(str1);


	for (int i = 0; i + num1 <= num2; i++)
	{
		int index = 0;
		for (int j = i; j < num1 + i; j++)
		{
			if (str1[j] != str[index])
			{
				ary[i]++;
			}
			index++;
		}
		index = 0;
	}

	int min = 60;

	for (int i = 0; i + num1 <= num2; i++)
	{
		if (ary[i] <= min)
		{
			min = ary[i];
		}
	}

	printf("%d\n", min);


}