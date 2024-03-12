#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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


int main(void)
{
	long long int num1 = 0;
	long long int num2 = 0;
	scanf("%lld %lld", &num1, &num2);

	long long int num3 = num1;
	long long int min = 9000000000000;
	long long int result1 = 0;
	long long int result2 = 0;
	while (1)
	{
		if (gcd(num3, (num1 * num2) / num3) == num1)
		{
			if (num2 % num3 == 0 && num2 % (num1 * num2 / num3) == 0)
			{
				if (min > num3 + (num1 * num2) / num3)
				{
					min = num3 + (num1 * num2) / num3;
					result1 = num3;
					result2 = (num1 * num2) / num3;
				}
				//printf("%lld %lld\n", num3, num1 * num2 / num3);
			}
			
		}
		num3 += num1;
		if (num3 > num1 * num2 / num3)
		{
			break;
		}
	}
	if (result1 != 0 && result2 != 0)
	{
		printf("%lld %lld\n", result1, result2);
	}

	//printf("%lld %lld\n", gcd(result1, result2), result1 * result2 / gcd(result1, result2));
}
