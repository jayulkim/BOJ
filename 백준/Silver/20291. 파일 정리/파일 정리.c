#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info
{
	char name[150];
}info;

info list[50000];

info type[50000];

info typelist[50000];

info typelist1[50000];
int ary1[50000] = { 0, };

int compare(const void* num1, const void* num2)
{
	info *a = (info*)num1;
	info *b = (info*)num2;

	return strcmp(a->name, b->name);
}


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%s", list[i].name);

		int num2 = strlen(list[i].name);

		int index = 0;
		for (int j = num2 - 1; j >= 0; j--)
		{
			if (list[i].name[j] == '.')
			{
				break;
			}
			type[i].name[index] = list[i].name[j];
			index++;
		}

		int index1 = 0;
		for (int j = index - 1; j >= 0; j--)
		{
			typelist[i].name[index1] = type[i].name[j];
			index1++;
		}
		
	}
	qsort(typelist, num1, sizeof(info), compare);

	int index2 = 0;
	for (int i = 0; i < num1; i++)
	{
		
		if (strcmp(typelist[i].name, typelist[i + 1].name) != 0)
		{
			strcpy(typelist1[index2].name, typelist[i].name);
			index2++;
		}
		else
		{
			ary1[index2]++;
		}
	}
	for (int i = 0; i < index2; i++)
	{
		printf("%s %d\n", typelist1[i].name, ary1[i] + 1);
	}

	
	

}