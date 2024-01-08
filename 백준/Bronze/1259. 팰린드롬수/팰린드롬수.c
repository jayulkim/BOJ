#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[99999];
	char str2[99999];
	
	
	while (1)
	{
		
		scanf(" %s", str1);
		int count = 0;
		int num1 = strlen(str1);

		if (str1[0] == '0')
		{
			break;
		}
	

		for (int i = num1 - 1; i >= 0; i--)
		{
			str2[num1 - i - 1] = str1[i];
			

		}

		for (int i = 0; i < num1; i++)
		{
			if (str1[i] != str2[i] && str1[0] != 0)
			{
				count += 1;
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