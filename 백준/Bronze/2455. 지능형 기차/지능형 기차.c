#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct info
{
	int in;
	int out;
}info;

info list[10];

int ary[10];
int sum[10];
int main(void)
{
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d", &list[i].out, &list[i].in);
		ary[i] = list[i].in - list[i].out;
		//printf("%d\n", ary[i]);
	}
	
	sum[0] = ary[0];
	int max = sum[0];
	for (int i = 1; i < 4; i++)
	{
		sum[i] = sum[i - 1] + ary[i];
		if (sum[i] > max)
		{
			max = sum[i];
		}
	
	}
	printf("%d\n", max);
	
}