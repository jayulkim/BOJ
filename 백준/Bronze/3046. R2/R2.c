#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);

	printf("%d", 2 * num2 - num1);
}