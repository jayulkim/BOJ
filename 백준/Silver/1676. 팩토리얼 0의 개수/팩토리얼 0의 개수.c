#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	long long int num2 = 1;
	int count1 = 0;
	int count2 = 0;
	for (long long int i = 2; i <= num1; i++)
	{
		int num3 = i;
		while (num3 % 2 == 0)
		{
			count1++;
			num3 /= 2;
		}
		while (num3 % 5 == 0)
		{
			count2++;
			num3 /= 5;
		}
	}
	if (count1 > count2)
	{
		printf("%d", count2);
	}
	else
	{
		printf("%d", count1);
	}


}