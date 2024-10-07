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

	if (num1 == 1)
	{
		printf("12 1600");
	}
	else if (num1 == 2)
	{
		printf("11 894");
	}
	else if (num1 == 3)
	{
		printf("11 1327");
	}
	else if (num1 == 4)
	{
		printf("10 1311");
	}
	else if (num1 == 5)
	{
		printf("9 1004");
	}
	else if (num1 == 6)
	{
		printf("9 1178");
	}
	else if (num1 == 7)
	{
		printf("9 1357");
	}
	else if (num1 == 8)
	{
		printf("8 837");
	}
	else if (num1 == 9)
	{
		printf("7 1055");
	}
	else if (num1 == 10)
	{
		printf("6 556");
	}
	else if (num1 == 11)
	{
		printf("6 773");
	}
}