#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char str[101];
int ary[30] = { 0, };

int main(void)
{
	scanf("%s", str);
	int num1 = strlen(str);
	for (int i = 0; i < 26; i++)
	{
		ary[i] = -1;
	}
	for (int i = 0; i < num1; i++)
	{
		if (ary[str[i] - 'a'] == -1)
		{
			ary[str[i] - 'a'] = i;
		}
		
		
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", ary[i]);
	}
	
}
