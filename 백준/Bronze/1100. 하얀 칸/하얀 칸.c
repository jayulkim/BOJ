#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
	char str1[10][10];

	for (int i = 0; i < 8; i++)
	{
		scanf("%s", str1[i]);
	}

	int result = 0;
	int count1 = 0;
	while (count1 <= 6)
	{

		int count = 0;

		while (count <= 6)
		{
			if (str1[count1][count] == 'F')
			{
				result++;
			}
			count = count + 2;
		}
		count1 = count1 + 2;
	}

	int count2 = 1;
	while (count2 <= 7)
	{
		int count3 = 1;

		while (count3 <= 7)
		{
			if (str1[count2][count3] == 'F')
			{
				result++;
			}
			count3 = count3 + 2;
		}
		count2 = count2 + 2;
	}

	printf("%d", result);
}