#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		long long int num2 = 0;
		long long int num3 = 0;
		int count1 = 0;
		scanf("%lld %lld", &num2, &num3);
		if (num2 == num3)
		{
			printf("0\n");
			count1++;
		}
		if (count1 == 0)
		{
			long long int result = 0;
			long long int count = 1;

			int case1 = 0;
			int case2 = 0;
			int case3 = 0;

			num2 += count;
			result++;
			while (1)
			{
				if (num2 == num3)
				{
					break;
				}
				else if (num2 + (count + 1) * (count) / 2 == num3)
				{
					case1++;
					break;
				}
				else if (num2 + (count + 1) * (count + 2) / 2 == num3)
				{
					case2++;
					break;
				}
				else if (num2 + (count - 1) * count / 2 == num3)
				{
					case3++;
					break;
				}
				if (num2 + (count + 1) * (count + 2) / 2 <= num3)
				{
					count++;
					num2 += count;
					result++;
				}
				else if (num2 + (count + 1) * count / 2 <= num3)
				{
					num2 += count;
					result++;
				}
				else if (num2 + (count - 1) * count / 2 <= num3)
				{
					count--;
					num2 += count;
					result++;
				}
			}
			if (case1 != 0)
			{
				result += count;
			}
			else if (case2 != 0)
			{
				result += (count + 1);
			}
			printf("%lld\n", result);
		}
	}
	
	
	
}