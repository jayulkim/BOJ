#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int ary1[1000010] = { 0, };
long long int ary2[1000010] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	if (num1 > 0)
	{
		ary1[0] = 0;
		ary1[1] = 1;
		int num2 = 0;
		for (int i = 2; i <= num1; i++)
		{
			ary1[i] = (ary1[i - 1] % 1000000000) + (ary1[i - 2] % 1000000000);
		}

		if (ary1[num1] > 0)
		{
			printf("1\n");
		}
		else if (ary1[num1] == 0)
		{
			printf("0\n");
		}
		else if (ary1[num1] < 0)
		{
			printf("-1\n");
		}
		printf("%lld\n", ary1[num1] % 1000000000);
	}
	else if (num1 == 0)
	{
		printf("0\n0");
	}
	else if (num1 < 0)
	{
		ary2[0] = 0;
		ary2[1] = 1;
		num1 = -num1;
		int num2 = 0;
		for (int i = 2; i <= num1; i++)
		{
			if (ary2[i - 2] >= 0 && ary2[i - 1] >= 0)
			{
				ary2[i] = (ary2[i - 2] % 1000000000) - (ary2[i - 1] % 1000000000);
			}
			else if (ary2[i - 2] < 0 && ary2[i - 1] >= 0)
			{
				ary2[i] = (-abs(ary2[i - 2]) % 1000000000) - (ary2[i - 1] % 1000000000);
			}
			else if (ary2[i - 2] >= 0 && ary2[i - 1] < 0)
			{
				ary2[i] = (ary2[i - 2] % 1000000000) + (abs(ary2[i - 1]) % 1000000000);
			}
			else if (ary2[i - 2] < 0 && ary2[i - 1] < 0)
			{
				ary2[i] = ((ary2[i - 2]) % 1000000000) + (abs(ary2[i - 1]) % 1000000000);
			}
			//printf("%lld\n", ary2[i]);
		}
		if (ary2[num1] > 0)
		{
			num2 = 1;
		}
		else if (ary2[num1] == 0)
		{
			num2 = 0;
		}
		else if (ary2[num1] < 0)
		{
			num2 = -1;
		}
		printf("%d\n", num2);
		
		printf("%lld\n", abs(ary2[num1]) % 1000000000);
	}

}
