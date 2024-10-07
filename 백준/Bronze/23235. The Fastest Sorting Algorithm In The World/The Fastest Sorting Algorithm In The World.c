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
	int count = 1;
	while (1)
	{
		gets(str);
		if (strcmp(str, "0") == 0)
		{
			break;
		}
		
		printf("Case %d: Sorting... done!\n", count);
		count++;

	}
	
}