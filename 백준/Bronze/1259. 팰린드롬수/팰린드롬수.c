#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

int main(void)
{
	while (1)
	{
		char num1[10];
		scanf("%s", num1);
		if (strcmp(num1, "0") == 0)
		{
			break;
		}
		int num2 = strlen(num1);

		int count = 0;
		for (int i = 0; i < num2 / 2; i++)
		{
			if (num1[i] != num1[num2 - 1 - i])
			{
				count++;
				break;
			}
		}
		if (count == 0)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}


	}


	
}