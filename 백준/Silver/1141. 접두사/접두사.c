#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[55][55];

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s", str[i]);
	}

	for (int i = 0; i < num1; i++)
	{
		int num2 = strlen(str[i]);

		for (int j = 0; j < num1; j++)
		{
			if (i != j)
			{
				int num3 = strlen(str[j]);

				if (num2 <= num3)
				{
					int count = 0;
					for (int k = 0; k < num2; k++)
					{
						if (str[i][k] != str[j][k])
						{
							count++;
							break;
						}
					}
					//printf("%d\n", count);
					if (count == 0)
					{
						strcpy(str[i], "");
						
						
					}
				}
			}
			
		}
		
	}
	int result = 0;
	for (int i = 0; i < num1; i++)
	{
	//	printf("%s", str[i]);
		if (strcmp(str[i], "") != 0)
		{
			result++;
		}
	}
	printf("%d\n", result);

}