#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ary[101];

int main(void)
{
	scanf("%s", ary);
	int size = strlen(ary);
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		if (ary[i] == ary[size - i - 1])
		{
			num += 0;
		}
		else
		{
			num += 1;
		}
	}
	if (num == 0)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	

}
