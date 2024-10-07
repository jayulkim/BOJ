#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char str[60];

char str1[60];

int main(void)
{
	scanf("%s", str);

	int num1 = strlen(str);

	int index = 0;
	for (int i = num1 - 2; i >= 0; i--)
	{
		str1[index] = str[i];
		index++;
	}
//	printf("%s", str1);
	
	int count1 = 0;
	for (int i = 1; i < num1; i++)
	{
		int index1 = 0;
		int count = 0;
		for (int j = i; j < num1; j++)
		{
			if (str1[index1] != str[j])
			{
				count++;
				break;
			}
			else
			{
				index1++;
			}


		}
		if (count == 0)
		{
			int index2 = 0;
			//printf("%d %d %d", i, index, i + index);
			for (int j = i; j <= num1 + i; j++)
			{
				str[j] = str1[index2];
				index2++;
			}
			//printf("%s", str);
			printf("%d\n", strlen(str));
			count1++;
			break;
		}



	}
	if (count1 == 0)
	{
		printf("%d\n", num1 + index);
	}


}