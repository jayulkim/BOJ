#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>



int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);


	int count = 0;

	long long int start1 = 666;

	long long int result = 0;
	while (count < num1)
	{
		if (start1 % 1000 == 666 || (start1 / 10) % 1000 == 666 || (start1 / 100) % 1000 == 666 || (start1 / 1000) % 1000 == 666|| (start1 / 10000) % 1000 == 666 || (start1 / 100000) % 1000 == 666 || (start1 / 1000000) % 1000== 666 || (start1 / 10000000) % 1000 == 666)
		{
			result = start1;
			count++;
		}
		
		start1++;
		
		

	}
	printf("%lld", result);

}