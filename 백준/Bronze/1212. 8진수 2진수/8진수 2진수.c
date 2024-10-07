#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char num1[500000];

typedef struct pos
{
	char number[1];
}pos;

pos list[500000];

int ary1[500000] = { 0, };

int ary2[333335][3] = {0,};

int ary3[1000600] = { 0, };

int main(void)
{
	scanf("%s", num1);

	int num3 = strlen(num1);

	for (int i = 0; i < num3; i++)
	{
		list[i].number[0] = num1[i];
		
	}

	for (int i = 0; i < num3; i++)
	{
		ary1[i] = (list[i].number[0] - 48);

	}

	for (int i = 0; i < num3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			ary2[i][j] = ary1[i] % 2;
			ary1[i] /= 2;
			
		}
	}
	int index = 0;
	for (int i = 0; i < num3; i++)
	{
		
		for (int j = 0; j < 3; j++)
		{
			ary3[index + j] = ary2[i][j];

		}
		index = index + 3;
	}
	int count = 0;
	for (int i = 0; i < num3 * 3; i++)
	{
		if (ary3[i] == 1)
		{
			break;
		}
		else
		{
			count++;
		}
		
	}
	if (atoi(num1) == 0)
	{
		printf("0\n");
	}
	else
	{
		for (int i = count; i < num3 * 3; i++)
		{
			printf("%d", ary3[i]);
		}
	}
	


}