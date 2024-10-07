#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		char str1[100] = {""};
		scanf("%s", str1);
		int ary[100] = { 0, };
		int num2 = strlen(str1);
		int index = 0;
		
		for (int j = 0; j < num2; j++)
		{
			if (str1[j] == 'O')
			{
				ary[index]++;
			}
			else if (str1[j] == 'X')
			{
				index++;
			}
			
		}
		int result = 0;
		for (int j = 0; j < num2; j++)
		{
			result += ary[j] * (ary[j] + 1) / 2;
		}
		printf("%d\n", result);
	}

}