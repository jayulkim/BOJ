#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char str[101];
int ary[30] = { 0, };

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d %s", &num2, str);
		int num3 = strlen(str);
		for (int k = 0; k < num3; k++)
		{
			for (int j = 0; j < num2; j++)
			{
				printf("%c", str[k]);
			}
			
		}
		printf("\n");
	}
}
