#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int ary[10] = { 0, };

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


char str[25];
int main(void)
{
	scanf("%s", str);
	if (strcmp(str, "NLCS") == 0)
	{
		printf("North London Collegiate School");
	}
	else if (strcmp(str, "BHA") == 0)
	{
		printf("Branksome Hall Asia");
	}
	else if (strcmp(str, "KIS") == 0)
	{
		printf("Korea International School");
	}
	else if (strcmp(str, "SJA") == 0)
	{
		printf("St. Johnsbury Academy");
	}
	
}