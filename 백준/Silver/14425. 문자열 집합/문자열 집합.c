#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info
{
	char word[1000];
}info;
info list[10000];
char list1[10000];
int compare(const void* num1, const void* num2)
{
	info *a = (info*)num1;
	info *b = (info*)num2;
	
	return strcmp(a->word, b->word);

}
int search(info* ary, int size, char *key)
{
	int start = 0, end = size - 1;
	while (start <= end) 
	{
		int cen = (start + end) / 2;

		if (strcmp(ary[cen].word, key) == 0)
		{
			return cen;
		}
		else if (strcmp(ary[cen].word, key) > 0)
		{
			end = cen - 1;
		}
		else if (strcmp(ary[cen].word, key) < 0)
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

	

	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s", list[i].word);
	}

	qsort(list, num1, sizeof(info), compare);

	int count = 0;
	for (int i = 0; i < num2; i++)
	{
		scanf("%s", list1);
		int result = search(list, num1, list1);
		if (result != -1)
		{
			count++;
		}
	}
	printf("%d\n", count);
}