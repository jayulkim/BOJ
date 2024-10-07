#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info
{
	char name[100];
}info;

info list[1100];

info list1[1100];

int compare(const void* num1, const void* num2) 
{
  info *a = (info*)num1;
  info *b = (info*)num2;
  return strcmp(a -> name, b -> name);

}
int main(void)
{
	int num1 = 0;
	int ary1[1100] = { 0, };

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s", list[i].name);
	}
	qsort(list, num1, sizeof(info), compare);

	int index = 0;
	for (int i = 0; i < num1; i++)
	{
		if (strcmp(list[i].name, list[i + 1].name) != 0)
		{
			strcpy(list1[index].name, list[i].name);
			
			index++;
		}
		else
		{
			ary1[index]++;
		}
		
	}
	int count = 0;
	int index1 = 0;
	
	for (int i = 0; i < index; i++)
	{
		if (ary1[i] > count)
		{
			count = ary1[i];
			index1 = i;
		}
	}

	printf("%s\n", list1[index1].name);
}