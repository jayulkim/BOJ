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
	//printf("%d %d", 'a', 'A');
	char num1[10];
	gets(num1);
	int num3 = atoi(num1);
	int count1 = 0;

	for (int i = 0; i < num3; i++)
	{
		
		gets(str);
		int num2 = strlen(str);
		for (int j = 0; j < 7; j++)
		{
			if (strcmp(str1[j], str) == 0)
			{
				count1++;
				break;
			}
		}

	}
	//printf("%d\n", count1);
	if (count1 == num3)
	{
		printf("No");
	}
	else
	{
		printf("Yes");
	}
}