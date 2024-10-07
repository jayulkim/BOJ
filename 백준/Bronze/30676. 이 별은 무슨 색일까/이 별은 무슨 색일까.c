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

	if (num1 >= 620 && num1 <= 780)
	{
		printf("Red");
	}
	else if (num1 >= 590 && num1 < 620)
	{
		printf("Orange");
	}
	else if (num1 >= 570 && num1 < 590)
	{
		printf("Yellow");
	}
	else if (num1 >= 495 && num1 < 570)
	{
		printf("Green");
	}
	else if (num1 >= 450 && num1 < 495)
	{
		printf("Blue");
	}
	else if (num1 >= 425 && num1 < 450)
	{
		printf("Indigo");
	}
	else if (num1 >= 380 && num1 < 425)
	{
		printf("Violet");
	}
}