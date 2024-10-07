#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char num1[55];
char result[500000][55];

int main(void)
{
	//printf("%d %d", '0', '9'); // 48 57
	scanf("%s", num1);
	int num2 = strlen(num1);
	if (num2 == 1)
	{
		printf("0\n");
		return 0;
	}

	int index = 0;
	
	for (int k = 0; k < num2; k += 2)
	{
		for (int j = 0; j < num2 - 1 - k; j++)
		{
			int index1 = 0;
			for (int i = j; i < j + k + 2; i++)
			{
				result[index][index1] = num1[i];
				index1++;
			}
			index++;
		}
	}
	int max = 0;
	for (int i = 0; i < index; i++)
	{
	//	printf("%s\n", result[i]);
		int num3 = strlen(result[i]);
		int sum1 = 0;
		int sum2 = 0;
		for (int j = 0; j < num3 / 2; j++)
		{
			sum1 += result[i][j] - 48;
		}
		for (int j = num3 / 2; j < num3; j++)
		{
			sum2 += result[i][j] - 48;
		}
		if (sum1 == sum2)
		{
			if (num3 > max)
			{
				max = num3;
			}
		}
	}
	printf("%d\n", max);
	
	

}