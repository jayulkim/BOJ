#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[11000] = { 0, };

int ary1[1100][3] = { 0, };

int main(void)
{
	for (int i = 2; i <= 10000; i++)
	{
		ary[i] = i;
	}
	for (int i = 2; i <= 5000; i++)
	{
		for (int j = i * 2; j <= 10000; j += i)
		{
			if (ary[i] != 0)
			{
				ary[j] = 0;
			}
		}
	}

	int num3 = 0;
	scanf("%d", &num3);

	for (int k = 0; k < num3; k++)
	{
		int num1 = 0;
		scanf("%d", &num1);


		int index = 0;
		for (int i = 2; i <= num1 / 2; i++)
		{
			if (ary[num1 - ary[i]] == num1 - ary[i])
			{
				ary1[index][0] = ary[i];
				ary1[index][1] = num1 - ary[i];
				index++;
			}
		}

		int min = 10000;

		int result = 0;
		for (int i = 0; i < index; i++)
		{
			if (ary1[i][1] - ary1[i][0] <= min)
			{
				min = ary1[i][1] - ary1[i][0];
				//printf("%d %d\n", ary1[i][0], ary1[i][1]);
				result = i;
			}
		}
		printf("%d %d\n", ary1[result][0], ary1[result][1]);
	}

	
	


}