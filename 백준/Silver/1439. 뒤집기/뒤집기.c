#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary0[1000001] = { 0, };
int ary1[1000001] = { 0, };

char str[1000001] = { 0, };

int main(void)
{
	scanf("%s", str);
	getchar();
	int num1 = strlen(str);

	int index0 = 0;
	int index1 = 0;

	for (int i = 0; i < num1; i++)
	{
		if (str[i] == '0')
		{
			ary0[index0]++;
			index1++;
			//printf("%d\n", ary0[index]);
		}
		else if (str[i] == '1')
		{
			ary1[index1]++;
		//	printf("%d\n", ary0[index]);
			index0++;
		}
	}
	int count0 = 0;
	for (int i = 0; i < num1; i++)
	{
		if (ary0[i] != 0)
		{
			count0++;
		//	printf("%d\n", ary0[i]);
		}
	}
	int count1 = 0;
	for (int i = 0; i < num1; i++)
	{
		if (ary1[i] != 0)
		{
			count1++;
			//printf("%d\n", ary1[i]);
		}
	}
	if (count0 == 0 || count1 == 0)
	{
		printf("0\n");
	}
	else
	{
		if (count0 < count1)
		{
			printf("%d\n", count0);
		}
		else if (count0 >= count1)
		{
			printf("%d\n", count1);
		}
	}

}