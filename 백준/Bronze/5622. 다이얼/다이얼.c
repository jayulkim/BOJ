#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	char str1[300];
	
	int count = 0;

	gets(str1);
	for (int i = 0; i < strlen(str1); i++)
	{
		if (str1[i] == 'A' || str1[i] == 'B' || str1[i] == 'C')
		{
			count += 2;
		}
		if (str1[i] == 'D' || str1[i] == 'E' || str1[i] == 'F')
		{
			count += 3;
		}
		if (str1[i] == 'G' || str1[i] == 'H' || str1[i] == 'I')
		{
			count += 4;
		}
		if (str1[i] == 'J' || str1[i] == 'K' || str1[i] == 'L')
		{
			count += 5;
		}
		if (str1[i] == 'M' || str1[i] == 'N' || str1[i] == 'O')
		{
			count += 6;
		}
		if (str1[i] == 'P' || str1[i] == 'Q' || str1[i] == 'R' || str1[i] == 'S')
		{
			count += 7;
		}
		if (str1[i] == 'T' || str1[i] == 'U' || str1[i] == 'V')
		{
			count += 8;
		}
		if (str1[i] == 'W' || str1[i] == 'X' || str1[i] == 'Y' || str1[i] =='Z')
		{
			count += 9;
		}
	}
	printf("%d", count + strlen(str1));
	
}