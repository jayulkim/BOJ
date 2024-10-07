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

	ary1[0] = 0;
	ary1[1] = 1;
	int num2 = 0;
	for (int i = 2; i <= num1; i++)
	{
		ary1[i] = (ary1[i - 1] + ary1[i - 2]) % 1000000007;
	}

	
	printf("%lld\n", ary1[num1] % 1000000007); 
	


}