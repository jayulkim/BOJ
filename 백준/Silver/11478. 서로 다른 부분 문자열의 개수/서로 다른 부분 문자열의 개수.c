#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct info
{
	char name[1001];
}info;

info list[500501];

int compare(const void* num1, const void* num2) 
{
  info* a = (info*)num1;
  info* b = (info*)num2;
  return strcmp(a->name, b->name);

}

int main(void)
{
	char str1[1001];
	scanf("%s", str1);

	int num1 = strlen(str1);

	int index = 0;
	
	int result = 0;
	for (int k = 0; k < num1; k++)
	{
		for (int i = k; i < num1; i++)
		{
			int index1 = 0;
			for (int j = k; j <= i; j++)
			{
				list[index].name[index1] = str1[j];
				index1++;
			}
			index++;
		}
	}

	qsort(list, index, sizeof(info), compare);


	for (int i = 0; i < index; i++)
	{
		if (strcmp(list[i].name, list[i + 1].name) != 0)
		{
			result++;
		}
	}
	
	printf("%d\n", result);
	
}
