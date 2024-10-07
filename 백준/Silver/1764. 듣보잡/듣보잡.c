#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct eme
{
	char name[30];
}eme;
typedef struct qh
{
	char name[30];
}qh;
typedef struct emeqh
{
	char name[30];
}emeqh;

eme list1[500000];
qh list2[500000];
emeqh list3[500000];

int compare1(const void* num1, const void* num2) 
{
  eme *a = (eme*)num1;
  eme *b = (eme*)num2;
  return strcmp(a->name, b->name);

}
int compare2(const void* num1, const void* num2)
{
	qh* a = (qh*)num1;
	qh* b = (qh*)num2;
	return strcmp(a->name, b->name);

}
int compare3(const void* num1, const void* num2)
{
	emeqh* a = (emeqh*)num1;
	emeqh* b = (emeqh*)num2;
	return strcmp(a->name, b->name);

}
int search1(eme* ary, int size, char *key)
{
	int start = 0, end = size -1;
	while (start <= end) 
	{
		int cen = (start + end) / 2;

		if (strcmp(ary[cen].name,key) == 0)
		{
			return cen; 
		}
		else if (strcmp(ary[cen].name, key) > 0)
		{
			end = cen - 1;
		}
		else if (strcmp(ary[cen].name, key) < 0)
		{
			start = cen + 1;
		}
	}
	return -1; 
}
int search2(qh* ary, int size, char* key)
{
	int start = 0, end = size -1;
	while (start <= end)
	{
		int cen = (start + end) / 2;

		if (strcmp(ary[cen].name, key) == 0)
		{
			return cen;
		}
		else if (strcmp(ary[cen].name, key) > 0)
		{
			end = cen - 1;
		}
		else if (strcmp(ary[cen].name, key) < 0)
		{
			start = cen + 1;
		}
	}
	return -1;
}
int main(void)
{
	int num1 = 0;
	int num2 = 0;

	int count = 0;
	int index = 0;

	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s", list1[i].name);
	}
	for (int i = 0; i < num2; i++)
	{
		scanf("%s", list2[i].name);
	}
	if (num1 > num2)
	{
		qsort(list2, num2, sizeof(qh), compare2);
		for (int i = 0; i < num1; i++)
		{
			int result = search2(list2, num2, list1[i].name);
			if (result != -1)
			{
				count++;
				strcpy(list3[index].name,list1[i].name);
				index++;

			}

		}
		qsort(list3, index, sizeof(emeqh), compare3);
		printf("%d\n", count);

		for (int i = 0; i < index; i++)
		{
			printf("%s\n", list3[i].name);
		}
	}
	else if (num2 >= num1)
	{
		qsort(list1, num1, sizeof(eme), compare1);
		for (int i = 0; i < num2; i++)
		{
		
			int result = search2(list1, num1, list2[i].name);
			if (result != -1)
			{
				count++;
				strcpy(list3[index].name, list2[i].name);
				index++;
				
			}
			

		}
		qsort(list3, index, sizeof(emeqh), compare3);
		printf("%d\n", count);

		for (int i = 0; i < index; i++)
		{
			printf("%s\n", list3[i].name);
		}
	}

}