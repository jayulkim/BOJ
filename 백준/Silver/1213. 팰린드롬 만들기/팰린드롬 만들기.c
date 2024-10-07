#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

char str[60];
char str1[60];
int ary[150] = { 0, };

int main(void)
{
	scanf("%s", str);

	int num1 = strlen(str);

	for (int i = 0; i < num1; i++)
	{
		int num2 = str[i];
		ary[num2]++;
	}
	int count = 0;
	for (int i = 0; i < 150; i++)
	{
		if (ary[i] != 0)
		{
			//printf("%c %d\n", i, ary[i]);
		}
		if (ary[i] % 2 == 1)
		{
			count++;
		}
	}
	if (count >= 2)
	{
		printf("I'm Sorry Hansoo\n");
	}
	else if (count == 1)
	{
		int index = 0;
		
		for (int i = 0; i < 150; i++)
		{
			if (ary[i] % 2 == 0)
			{
				for (int j = 0; j < ary[i] / 2; j++)
				{
					str1[index] = i;
					//printf("%s", str1);
					index++;
				}

			}
			else if (ary[i] % 2 == 1)
			{
				for (int j = 0; j < ary[i] / 2; j++)
				{
					str1[index] = i;
					//printf("%s", str1);
					index++;
				}
				str1[num1 / 2] = i;
			}
		}
		for (int i = num1 - 1; i >= num1 / 2 + 1; i--)
		{
			str1[i] = str1[num1 - 1 - i];
		}
		printf("%s\n", str1);
	}
	else if (count == 0)
	{
		int index1 = 0;
		for (int i = 0; i < 150; i++)
		{
			if (ary[i] % 2 == 0)
			{
				for (int j = 0; j < ary[i] / 2; j++)
				{
					str1[index1] = i;
					//printf("%s", str1);
					index1++;
				}

			}
		}
		for (int i = num1 - 1; i >= num1 / 2; i--)
		{
			str1[i] = str1[num1 - 1 - i];
		}
		printf("%s", str1);

	}
	
}