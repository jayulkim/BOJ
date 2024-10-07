#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char num1[1000005];

int main(void)
{
	scanf("%s", num1);

	int num4 = strlen(num1);
	if (num4 == 1)
	{
		if (atoi(num1) == 3 || atoi(num1) == 6 || atoi(num1) == 9)
		{
			printf("0\nYES\n");
			return 0;
		}
		else
		{
			printf("0\nNO\n");
			return 0;
		}
	}
	int num3 = 0;
	for (int i = 0; i < num4; i++)
	{
		num3 += (num1[i] - 48);
	}
	
	int result = 0;
	while (num3 >= 10)
	{
		int num5 = num3;
		int count = 0;
		while (num5 >= 1)
		{
			count += (num5 % 10);
			num5 /= 10;
		}
		num3 = count;
		result++;
	//	printf("%d\n", num3);

	}
	printf("%d\n", result + 1);

	if (num3 == 3 || num3 == 6 || num3 == 9)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

}