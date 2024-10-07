#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[10005] = { 0, };

int ary1[1000] = { 0, };

int main(void)
{
	for (int i = 2; i <= 5000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = 2 * i; j <= 10000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	ary1[2] = 1;
	ary1[4] = 1;
	ary1[16] = 1;
	ary1[20] = 1;
	ary1[24] = 1;
	ary1[42] = 1;
	ary1[37] = 1;
	ary1[58] = 1;
	ary1[89] = 1;
	ary1[85] = 1;
	ary1[73] = 1;
	ary1[98] = 1;
	ary1[145] = 1;
	ary1[541] = 1;
	ary1[61] = 1;
	ary1[154] = 1;
	ary1[451] = 1;
	ary1[415] = 1;
	ary1[514] = 1;

	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int num3 = 0;
		scanf("%d %d", &num2, &num3);
		if (num3 < 7)
		{
			printf("%d %d NO\n", num2, num3);
		}
		else
		{
			if (ary[num3] != 0)
			{
				printf("%d %d NO\n", num2, num3);
			}
			else
			{
				int sum = 0;
				int count = num3;
				while (1)
				{
					while (count >= 1)
					{
						sum += (count % 10) * (count % 10);
						count /= 10;
					}
					if (ary1[sum] != 0)
					{
						printf("%d %d NO\n", num2, num3);
						break;
					}
					else
					{
						if (sum == 1)
						{
							printf("%d %d YES\n", num2, num3);
							break;
						}
						else
						{
							count = sum;
							sum = 0;
						}
					}
				}
			}
		}
	}

}