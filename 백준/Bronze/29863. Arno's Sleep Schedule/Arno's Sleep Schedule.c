#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>

int ary[10000] = { 0, };

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
char str1[10][100] = { {"Never gonna give you up"}, {"Never gonna let you down"}, {"Never gonna run around and desert you"}
, {"Never gonna make you cry"}, {"Never gonna say goodbye"}, {"Never gonna tell a lie and hurt you"}, {"Never gonna stop"}, };

char str[115];
char str2[115];

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d", &num1);
	scanf("%d", &num2);
	if (num1 > 3)
	{
		printf("%d", 24 - num1 + num2);
	}
	else if (num1 <= 3)
	{
		printf("%d", num2 - num1);
	}

	
}