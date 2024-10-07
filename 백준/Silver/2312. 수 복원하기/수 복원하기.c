#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

int ary[110000] = { 0, };

int ary1[110000] = { 0, };

int ary2[110000] = { 0, };
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
	int index = 0;
	for (int i = 2; i <= 100000; i++)
	{
		if (ary[i] != 0)
		{
			ary1[index] = ary[i];
			index++;
		}	
	}

	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);

		int count = 0;
		while (ary[num2] == 0)
		{
			if (num2 % ary1[count] == 0)
			{
				ary2[ary1[count]]++;
				num2 /= ary1[count];
			}
			else
			{
				count++;
			}
		}
		ary2[num2]++;

		for (int j = 0; j <= 100000; j++)
		{
			if (ary2[j] != 0)
			{
				printf("%d %d\n", j, ary2[j]);
				ary2[j] = 0;
			}
		}

	}


}