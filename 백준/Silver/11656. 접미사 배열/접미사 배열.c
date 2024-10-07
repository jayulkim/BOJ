#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info
{
	char str1[1100];
}info;

info list[1100];

int compare(const void* num1, const void* num2) 
{
  info *a = (info*)num1;
  info *b = (info*)num2;
  return strcmp(a -> str1, b -> str1);

}
int main(void)
{
	char str1[1100];

	scanf("%s", str1);

	int num1 = strlen(str1);

	
	
	for (int i = 0; i < num1; i++)
	{
		int index = 0;
		for (int j = i; j < num1; j++)
		{
			list[i].str1[index] = str1[j];
			
			index++;
		}

	}
	qsort(list, num1, sizeof(info), compare);

	for (int i = 0; i < num1; i++)
	{
		printf("%s\n", list[i].str1);
	}
	

}