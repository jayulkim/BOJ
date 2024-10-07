#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char str1[10005];
int ary[135] = { 0, };
int result[1000005] = { 0, };
typedef struct info
{
	int ary1[10005];
	int index;
}info;
info map[135] = { 0, };

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int index1 = 0;
		scanf("%s", str1);
		int need = 0;
		scanf("%d", &need);
		int num2 = strlen(str1);
		for (int j = 0; j < num2; j++)
		{
			ary[str1[j]]++;
		}
		for (int j = 0; j < num2; j++)
		{
			if (ary[str1[j]] >= need)
			{
				map[str1[j]].ary1[map[str1[j]].index] = j;
				map[str1[j]].index++;
			}
		}
		for (int j = 97; j <= 130; j++)
		{
			if (map[j].index != 0)
			{
				for (int k = 0; k + need - 1 < map[j].index; k++)
				{
					result[index1] = map[j].ary1[k + need - 1] - map[j].ary1[k] + 1;
					index1++;
				}
				map[j].index = 0;
			}
		}
		qsort(result, index1, sizeof(int), compare);
		if (index1 == 0)
		{
			printf("-1\n");
		}
		else
		{
			if (need == 1)
			{
				printf("%d %d\n", 1, 1);
			}
			else
			{
				printf("%d %d\n", result[0], result[index1 - 1]);
			}	
		}
		memset(result, 0, sizeof(result));
		memset(ary, 0, sizeof(ary));
	}
}

