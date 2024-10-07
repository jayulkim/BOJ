#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[25] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		char def[10];
		int num = 0;

		scanf("%s %d", def, &num);
		if (strcmp(def, "add") == 0)
		{
			if (stack[num] == 0)
			{
				stack[num] = 1;
			}
		}
		else if (strcmp(def, "remove") == 0)
		{
			if (stack[num] == 1)
			{
				stack[num] = 0;
			}
		}
		else if (strcmp(def, "check") == 0)
		{
			if (stack[num] == 0)
			{
				printf("0\n");
			}
			else
			{
				printf("1\n");
			}
		}
		else if (strcmp(def, "toggle") == 0)
		{
			if (stack[num] == 0)
			{
				stack[num] = 1;
			}
			else
			{
				stack[num] = 0;
			}
		}
		else if (strcmp(def, "all") == 0)
		{
			for (int j = 1; j <= 20; j++)
			{
				stack[j] = 1;
			}
		}
		else if (strcmp(def, "empty") == 0)
		{
			for (int j = 1; j <= 20; j++)
			{
				stack[j] = 0;
			}
		}



	}


}