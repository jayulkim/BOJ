#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct info
{
	char site[30];
	char password[30];
}info;

info list[100005];
char point[100005][30];

int compare(const void* num1, const void* num2)
{
	info *a = (info*)num1;
	info* b = (info*)num2;

	return strcmp(a->site, b->site);
}

int lower_bound(info* ary, int size, char *key)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (strcmp(ary[cen].site, key) >= 0)
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return end;
}

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s %s", list[i].site, list[i].password);
	}
	for (int i = 0; i < num2; i++)
	{
		scanf("%s", point[i]);
	}
	qsort(list, num1, sizeof(info), compare);
	for (int i = 0; i < num1; i++)
	{
		//printf("%s %s\n", list[i].site, list[i].password);
	}
	for (int i = 0; i < num2; i++)
	{
		int result = lower_bound(list, num1, point[i]);
		//printf("%d\n", result);
		printf("%s\n", list[result].password);
	}

}