#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[1000005] = { 0, };
long long int ary1[1000005] = { 0, };

int ary2[1000] = { 0, };

int main(void)
{
	for (int i = 2; i <= 500000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = 2 * i; j <= 1000000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (long long int i = 2; i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
			ary1[index] = i;
			index++;
		}
	}

	ary2[4] = 1;
	ary2[16] = 1;
	ary2[61] = 1;
	ary2[37] = 1;
	ary2[73] = 1;
	ary2[58] = 1;
	ary2[85] = 1;
	ary2[89] = 1;
	ary2[98] = 1;
	ary2[145] = 1;
	ary2[154] = 1;
	ary2[415] = 1;
	ary2[451] = 1;
	ary2[541] = 1;
	ary2[514] = 1;
	ary2[42] = 1;
	ary2[24] = 1;
	ary2[20] = 1;
	ary2[2] = 1;
	
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < index; i++)
	{
		if (ary1[i] > num1)
		{
			break;
		}
		
		long long int num2 = ary1[i];
		while (1)
		{
			long long int sum = 0;
			
			while (num2 >= 1)
			{
				sum += ((num2 % 10) * (num2 % 10));
				num2 /= 10;
			}
			if (sum == 1)
			{
				printf("%d\n", ary1[i]);
				break;
			}
			else
			{
				if (ary2[sum] == 1)
				{
					break;
				}
			}
			num2 = sum;



		}
	}

}
