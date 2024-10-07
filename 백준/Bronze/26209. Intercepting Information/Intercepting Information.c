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



int main(void)
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &ary[i]);
		if (ary[i] == 9)
		{
			count++;
		}
	}
	if (count == 0)
	{
		printf("S");
	}
	else
	{
		printf("F");
	}
	
}