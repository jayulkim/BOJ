#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[2100005] = { 0, };

int ary2[2100005] = { 0, };

int main(void)
{
	for (int i = 2; i <= 2100000; i++)
	{
		ary[i] = i;
	}
	for (int i = 2; i <= 2100000; i++)
	{
		for (int j = i * 2; j <= 2100000; j += i)
		{
			if (ary[i] != 0)
			{
				ary[j] = 0;
			}
		}
	}

	int index1 = 0;

	for (int i = 2; i <= 2100000; i++)
	{	
		if (ary[i] != 0)
		{
			int ary1[100] = { 0, };
			int num1 = ary[i];
			int index = 0;
			while (num1 >= 1)
			{
				ary1[index] = num1 % 10;
				num1 /= 10;
				index++;
			}
			int count = 0;
			for (int j = 0; j < index / 2; j++)
			{
				if (ary1[j] != ary1[index - 1 - j])
				{
					count++;
					break;
				}
			}
			if (count == 0)
			{
				ary2[index1] = ary[i];
				index1++;
			}
		}
	}

	int num2 = 0;
	scanf("%d", &num2);

	int num3 = 0;
	for (int i = 0; i < index1; i++)
	{
		if (num2 <= ary2[i])
		{
			num3 = i;
			break;
		}
	}
	printf("%d\n", ary2[num3]);
}