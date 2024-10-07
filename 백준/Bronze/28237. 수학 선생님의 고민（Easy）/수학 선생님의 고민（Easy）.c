#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int aryc[3000005] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	int index = 0;
	int count = 1;
	while (count <= num1)
	{
		if (num1 % count == 0)
		{
			aryc[index] = count; 
			//printf("%d\n", aryc[index]);// c값 후보 구하기
			index++;
		}
		count++;
	}

	long long int b = 0;

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	for (int i = index - 1; i >= 0; i--)
	{
		long long int b1 = 1;
		while (b1 <= 4 * (num1 + 1) / (2 * aryc[i]))
		{
			if (b1 * aryc[i] - ((num1 + 2) / b1) * (num1 / aryc[i]) == num1 + 1 && (num1 + 2) % b1 == 0 && num1 % aryc[i] == 0)
			{
				if ((num1 + 2) % b1 == 0) // d가 정수이면
				{
					count1++;
					printf("%lld %lld %lld %lld", num1 / aryc[i], b1, aryc[i], (-(num1 + 2) / b1));
					return 0;
				}
			}
			
			b1++;
		}
		long long int b2 = -1;
		while (b2 >= -2 * (num1 + 1) / (2 * aryc[i]))
		{
			if (b2 * aryc[i] + ((num1 + 2) / -b2) * (num1 / aryc[i]) == num1 + 1 && (num1 + 2) % -b2 == 0 && num1 % aryc[i] == 0)
			{
				if ((num1 + 2) % -b2 == 0)
				{
					count1++;
					printf("%lld %lld %lld %lld", num1 / aryc[i], b2, aryc[i], ((num1 + 2) / -b2));
					return 0;
				}
			}
			b2--;
		}
	}
	printf("-1");
}