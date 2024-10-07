#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>



int main(void)
{
	int num1 = 0;
	scanf(" %d ", &num1);
	for (int i = 0; i < num1; i++)
	{
		char str[55];
		gets(str);
		printf("%d. %s\n", i + 1, str);
		memset(str, NULL, sizeof(str));
	}
}