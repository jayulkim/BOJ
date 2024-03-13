#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[100005] = { 0, };

long long int gcd(long long int num1, long long int num2)
{
	long long int temp = num1 % num2;
	while (temp > 0)
	{
		num1 = num2;
		num2 = temp;
		temp = num1 % num2;
	}
	return num2;
}

long long int ary1[100005] = { 0, };
long long int ary2[100005] = { 0, };
int main(void)
{
	long long int num1 = 0;
	long long int num2 = 0;
	scanf("%lld %lld", &num1, &num2);

	for (int i = 2; i <= 50000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * 2; j <= 100000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	//printf("%d", ary[99989]);
	int index = 0;
	for (long long int i = 2; i <= 100000; i++)
	{
		if (ary[i] == 0)
		{
			ary1[index] = i;
			index++;
		}
	}
	//printf("%d", index);
	if (num1 == gcd(num1, num2))
	{
		long long int num3 = num2 / num1;
		long long int count = 1;
		int index1 = 0;
		while (num3 > 1)
		{
			if (num3 % ary1[index1] == 0)
			{
				ary2[ary1[index1]]++;
				num3 /= ary1[index1];
			}
			else
			{
				index1++;
				if (ary1[index1] == 0)
				{
					for (int i = 2; i <= 100000; i++)
					{
						if (ary2[i] != 0)
						{
							count *= (ary2[i] + 1);
						}
					}
					printf("%d", count * 2);
					return 0;
				}
			}
			
		}
		for (int i = 2; i <= 100000; i++)
		{
			if (ary2[i] != 0)
			{
				count *= (ary2[i] + 1);
			}
		}
		printf("%lld\n", count);

	}
	else
	{
		printf("0\n");
	}
}


