#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[30] = { 0, };

char str[1000];

int main(void)
{

	scanf("%s", str);

	int num1 = strlen(str);
	
	for (int i = 0; i < num1; i++)
	{
		ary[str[i] - 97]++;
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", ary[i]);
	}
	


}