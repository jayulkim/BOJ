#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct info
{
	char name[150];
}info;

info list[2000];

info study[2000];
info boj[2000];

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;

	if (strlen(a->name) > strlen(b->name))
	{
		return 1;
	}
	else if (strlen(a->name) < strlen(b->name))
	{
		return -1;
	}
	else
	{
		return strcmp(a->name, b->name);
	}
}


int main(void)
{
	char num1[10];

	gets(num1);
	
	int indexboj = 0;
	int indexstudy = 0;
	for (int i = 0; i < atoi(num1); i++)
	{
		gets(list[i].name);
		int num2 = strlen(list[i].name);

		if (list[i].name[0] == 'b' && list[i].name[1] == 'o' && list[i].name[2] == 'j' && list[i].name[3] == '.' && list[i].name[4] == 'k' && list[i].name[5] == 'r' && list[i].name[6] == '/')
		{
			int count = 0;
			for (int j = 7; j < num2; j++)
			{
				if (!isdigit(list[i].name[j]))
				{
					count++;
					break;
				}
			}
			if (count == 0)
			{
				strcpy(boj[indexboj].name, list[i].name);
				indexboj++;
			}
			else
			{
				strcpy(study[indexstudy].name, list[i].name);
				indexstudy++;
			}
		}
		else
		{
			strcpy(study[indexstudy].name, list[i].name);
			indexstudy++;
		}
		
	}
	qsort(study, indexstudy, sizeof(info), compare);
	for (int i = 0; i < indexstudy; i++)
	{
		printf("%s\n", study[i].name);
	}
	qsort(boj, indexboj, sizeof(info), compare);
	for (int i = 0; i < indexboj; i++)
	{
		printf("%s\n", boj[i].name);
	}
	


}