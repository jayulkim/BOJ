#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[105] = { 0, };

int main(void)
{
	char str1[20];
	char str2[20];
	char str3[20];
	char str4[20];
	
	int index1 = 0;
	char str5[40];


	scanf("%s %s %s %s", str1, str2, str3, str4);
	int num1 = strlen(str1);
	int num2 = strlen(str2);
	for (int i = 0; i < num1; i++)
	{
		str5[index1] = str1[i];
		index1++;
	}

	for (int i = 0; i < num2; i++)
	{
		str5[index1] = str2[i];
		index1++;
	}
//	printf("%s", str5);
	int index2 = 0;
	char str6[40];
	int num3 = strlen(str3);
	int num4 = strlen(str4);

	for (int i = 0; i < num3; i++)
	{
		str6[index2] = str3[i];
		index2++;
	}
	for (int i = 0; i < num4; i++)
	{
		str6[index2] = str4[i];
		index2++;
	}
//	printf("%s", str6);

	long long int num5 = atoll(str5);
	long long int num6 = atoll(str6);
	printf("%lld\n", num5 + num6);
}