#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char str[300];
int ary[100005] = { 0, };

int main(void)
{
	for (int i = 2; i <= 100000; i++)
	{
		ary[i] = i;
	}
	for (int i = 2; i <= 100000; i++)
	{
		if (ary[i] != 0)
		{
			for (int j = 2 * i; j <= 100000; j += i)
			{
				ary[j] = 0;
			}
		}
	}

	while (1)
	{
		scanf("%s", str);

		if (atoi(str) == 0)
		{
			break;
		}
		int num1 = strlen(str);

		int max = 0;

		int index = 0;
		char str1[300];
		for (int k = 0; k < 6; k++)
		{		
			for (int j = 0; j <= num1 - k; j++)
			{
				for (int i = j; i < j + k; i++)
				{
					str1[index] = str[i];
					index++;
				}
				long long int num2 = atoi(str1);
				//printf("%lld\n", num2);
				if (ary[num2] == num2 && num2 >= max)
				{
					//printf("%d\n", 11111);
					max = num2;
				}
				for (int i = 0; i < index; i++)
				{
					str1[i] = NULL;
				}
				index = 0;
				
			}
		}
		
		printf("%d\n", max);

	}

}

