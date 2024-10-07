#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


long long int ary[1005] = { 0, };

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	ary[0] = 1;
	ary[1] = 1;

	for (int i = 2; i <= num1; i++)
	{
		ary[i] = ary[i - 1] + ary[i - 2];
	}
	printf("%lld\n", 2 * ary[num1] + 2 * ary[num1 -1]);

}