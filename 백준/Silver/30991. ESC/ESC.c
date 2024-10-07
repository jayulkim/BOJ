#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long int a[40] = { 0, };
long long int b[40] = { 0, };
long long int c[40] = { 1, };
int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 1; i <= num1; i++)
	{
		c[i] = 2 * a[i - 1] - 2 * b[i - 1] + c[i - 1];
		a[i] = a[i - 1] - c[i - 1];
		b[i] = b[i - 1] + c[i - 1];
		//printf("%lld, %lld, %lld\n", a[i], b[i], c[i]);
		
	}
	printf("%lld", a[num1] + b[num1] + c[num1]);

}