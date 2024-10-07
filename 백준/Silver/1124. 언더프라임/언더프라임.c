#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[100005] = { 0, };
int ary1[100005] = { 0, };

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
	int num2 = 0;

	scanf("%d %d", &num1, &num2);

	int result = 0;
	for (int i = num1; i <= num2; i++)
	{
		int num3 = i;
		int index1 = 0;
		int count = 0;
		while (ary[num3] != num3)
		{
			if (num3 % ary1[index1] == 0)
			{
				num3 /= ary1[index1];
				count++;
			}
			else
			{
				index1++;
			}
		}
		count++;
		//printf("%d %d\n", num3, count);
		if (ary[count] == count)
		{
			result++;
		}

	}
	printf("%d\n", result);


}


