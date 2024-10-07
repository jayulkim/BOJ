#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>



int main(void)
{
	long long int num1 = 0;
	scanf("%lld", &num1);

	long long int count = 1;

	long long sum = 0;

	long long last = 0;
	while (sum <= num1)
	{
		sum += count;
		last = count;
		count++;
	}
	sum = sum - last;
	last--;

	while (num1 - sum <= last)
	{
		sum = sum - last;
		last--;
	}
	if (num1 == 2)
	{
		printf("1");
	}
	else
	{
		printf("%lld", last + 1);
	}
	





}