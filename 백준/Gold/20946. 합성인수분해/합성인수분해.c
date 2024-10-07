#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[1000005] = { 0, };

long long int ary2[1000005] = { 0, };

long long int result[1000005] = { 0, };

int main(void)
{
	for (int i = 2; i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * 2; j <= 1000000; j += i)
			{
				ary[j] = 1;
			}
		}

	}
	int index1 = 0;
	for (int i = 2; i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
			ary2[index1] = i;
			//printf("%d ", ary2[index1]);
			index1++;
		}
	}
//	printf("%d\n", index1);
	//printf("%d\n", ary2[330]);
	long long int num1 = 0;
	scanf("%lld", &num1);
	
	int index2 = 0;
	int index = 0;
	while (num1 > 1)
	{
		if (num1 % ary2[index] == 0)
		{
			result[index2] = ary2[index];
			index2++;
			num1 /= ary2[index];
		}
		else
		{
			index++;
			if (ary2[index] == 0)
			{
				result[index2] = num1;
				index2++;
				break;
			}
		}
	}
	for (int i = 0; i < index2; i++)
	{
		//printf("%lld ", result[i]);
	}
	if (index2 == 1)
	{
		printf("-1");
		return 0;
	}
	else
	{
		if (index2 % 2 == 0)
		{
			long long int num2 = 0;
			for (int i = 0; i < index2; i+= 2)
			{
				//printf("%lld ", result[i]);
				num2 = result[i] * result[i + 1];
				printf("%lld ", num2);
			}
		}
		else
		{
			long long int num2 = 0;
			for (int i = 0; i < index2 - 3; i+= 2)
			{
				num2 = result[i] * result[i + 1];
				printf("%lld ", num2);
			}
			printf("%lld ", result[index2 - 1] * result[index2 - 2] * result[index2 - 3]);
		}
	}
}