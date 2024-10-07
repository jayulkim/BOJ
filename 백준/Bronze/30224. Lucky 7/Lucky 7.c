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


char str2[115];

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	int num2 = num1;
	int index = 0;
	while (num2 >= 1)
	{
		ary[index] = num2 % 10;
		index++;
		num2 /= 10;
	}
	int count = 0;
	for (int i = 0; i < index; i++)
	{
		if (ary[i] == 7)
		{
			count++;
		}
	}
	if (num1 % 7 != 0 && count == 0)
	{
		printf("0");
	}
	else if (num1 % 7 == 0 && count == 0)
	{
		printf("1");
	}
	else if (count != 0 && num1 % 7 != 0)
	{
		printf("2");
	}
	else if (count != 0 && num1 % 7 == 0)
	{
		printf("3");
	}

	
}