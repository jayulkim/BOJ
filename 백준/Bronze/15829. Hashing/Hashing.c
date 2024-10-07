#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char str[60];


int main(void)
{
	int num = 0;
	scanf("%d", &num);
	scanf("%s", str);
	int num1 = strlen(str);

	long long int sum = 0;
	//printf("%d", 'a'); 97
	for (int i = 0; i < num1; i++)
	{
		long long int num2 = 1;
		for (int j = 0; j < i; j++)
		{
			num2 *= 31;
			num2 %= 1234567891;
		}

		sum += num2 * (str[i] - 96);
		sum %= 1234567891;
	}
	printf("%lld\n", sum);

}