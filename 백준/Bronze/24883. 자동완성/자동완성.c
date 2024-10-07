#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int main(void)
{
	scanf("%s", str);
	if (str[0] == 'n' || str[0] == 'N')
	{
		printf("Naver D2\n");
	}
	else
	{
		printf("Naver Whale\n");
	}
	
}