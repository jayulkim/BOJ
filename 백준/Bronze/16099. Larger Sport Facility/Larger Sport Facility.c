#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ary[5] = { 0, };

int compare(const void* num1, const void* num2)
{
	int a = *(int*)num1;
	int b = *(int*)num2;
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return -1;
	}
	else
	{
		return 0;
	}

}

char str[1000005];
char str1[1000005];
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		long long int num1 = 0;
		long long int num2 = 0;
		long long int num3 = 0;
		long long int num4 = 0;
		scanf("%lld %lld %lld %lld", &num1, &num2, &num3, &num4);

		if (num1 * num2 == num3 * num4)
		{
			printf("Tie\n");
		}
		else if (num1 * num2 > num3 * num4)
		{
			printf("TelecomParisTech\n");
		}
		else
		{
			printf("Eurecom\n");
		}

	}

	

}