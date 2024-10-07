#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct info
{
	char name[50];
}info;

info list[150];

info list1[150];

int ary1[150] = { 0, };

int compare(const void* num1, const void* num2) 
{
  info* a = (info*)num1;
  info* b = (info*)num2;
  
  return strcmp(a->name, b->name);
  

}
int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s", list[i].name);
	}
	qsort(list, num1, sizeof(info), compare);

	int index = 0;
	for (int i = 0; i < num1; i++)
	{
		if (list[i].name[0] != list[i + 1].name[0])
		{
			list1[index].name[0] = list[i].name[0];
			
			index++;
		}
		else
		{
			ary1[index]++;
		}

	}

	for (int i = 0; i < index; i++)
	{
		ary1[i]++;
	}
	int count = 0;
	for (int i = 0; i < index; i++)
	{

		if (ary1[i] >= 5)
		{
			printf("%c", list1[i].name[0]);
			count++;
		}

	}
	if (count == 0)
	{
		printf("PREDAJA\n");
	}

}