#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <memory.h>

typedef struct info
{
	char kind[5];
	int w;
	int h;
	int l;
}info;
info list[105];

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	int result1 = 0;
	int result2 = 0;
	int count = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%s %d %d %d", list[i].kind, &list[i].w, &list[i].h, &list[i].l);
		if (strcmp(list[i].kind, "A") == 0)
		{
			count++;
			result1 += (list[i].w / 12) * (list[i].h / 12) * (list[i].l / 12);
		}
		else
		{
			result2 += (120 * 50);
		}
	}
	//printf("%d %d", result1, result2);
	printf("%d\n", result2 + 1000 * count + 500 * result1);
	printf("%d", result1 * 4000);
}