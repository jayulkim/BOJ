#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char num1[100];
char num2[100];

int main(void)
{
	scanf("%s %s", num1, num2);

	int num3 = strlen(num1);
	int num4 = strlen(num2);

	if (num4 > num3)
	{
		printf("0\n");
	}
	else if (num3 == num4)
	{
		int count = 0;
		for (int i = 0; i <= num3; i++)
		{
			if (num1[i] == num2[i])
			{
				if (num1[i] == '8')
				{
					count++;
				}
			}
			else
			{
				break;
			}
		}
		printf("%d\n", count);
		
	}

}



