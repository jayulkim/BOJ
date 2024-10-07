#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct pos
{
	char word[55];
	
}pos;
int compare(const void* num1, const void* num2) 
{
  pos* a = (pos*)num1;
  pos* b = (pos*)num2;
  if (strlen(a -> word) > strlen(b->word))
  {
	  return 1;
  }
  else if (strlen(a->word) < strlen(b->word))
  {
	  return -1;
  }
  else
  {
	  return strcmp(a->word, b->word);
  }
}
int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);
	pos* str = (pos*)malloc(sizeof(pos) * num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%s", str[i].word);
	}
	qsort(str, num1, sizeof(pos), compare);


	for (int i = 0; i < num1; i++)
	{
		if (strcmp(str[i].word, str[i + 1].word) != 0)
		{
			printf("%s\n", str[i].word);
		}
		
	}
	
	free(str);
}