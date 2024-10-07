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
	
	for (int i = 0; i < num1; i++)
	{
		char str[50];
		scanf("%s", str);
		if (strcmp(str, "Algorithm") == 0)
		{
			printf("204\n");
		}
		else if (strcmp(str, "DataAnalysis") == 0)
		{
			printf("207\n");
		}
		else if (strcmp(str, "ArtificialIntelligence") == 0)
		{
			printf("302\n");
		
		}
		else if (strcmp(str, "CyberSecurity") == 0)
		{
			printf("B101\n");
		}
		else if (strcmp(str, "Network") == 0)
		{
			printf("303\n");
		}
		else if (strcmp(str, "Startup") == 0)
		{
			printf("501\n");
		}
		else if (strcmp(str, "TestStrategy") == 0)
		{
			printf("105\n");
		}
	}

	
}