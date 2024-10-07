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



int main(void)
{
	int num2 = 0;
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++)
	{
		char str[1005];
		scanf("%s", str);
		int num1 = strlen(str);

		if (num1 >= 6 && num1 <= 9)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	
	
	
}