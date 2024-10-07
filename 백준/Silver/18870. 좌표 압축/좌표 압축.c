#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[1000005] = { 0, };

typedef struct info
{
	int number;
	int index;
	int level;
}info;

info list[1000005];

int compare(const void* num1, const void* num2) 
{
  info *a = (info*)num1;
  info *b = (info*)num2;
  if (a -> number> b->number)
  {
	  return 1;
  }
  else if (a->number < b->number)
  {
	  return -1;
  }
  else
  {
	  return 0;
  }

}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &list[i].number);
		list[i].index = i;
	}

	int count = -1;
	int min = -1000000005;

	qsort(list, num1, sizeof(info), compare);

	for (int i = 0; i < num1; i++)
	{
		if (list[i].number > min)
		{
			list[i].level = ++count;
			min = list[i].number;
		}
		else
		{
			list[i].level = count;
		}
		//printf("%d\n", list[i].level);
		//printf("%d\n", list[i].index);
		ary[list[i].index] = list[i].level;
	}
	for (int i = 0; i < num1; i++)
	{
		printf("%d ", ary[i]);
	}
	

	
}