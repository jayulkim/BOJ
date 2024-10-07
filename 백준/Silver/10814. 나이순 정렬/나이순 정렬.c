#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct pos
{
	int age;
	char name[150];
}pos;

int compare(const void* num1, const void* num2)
{
  pos* a = (pos*)num1;
  pos* b = (pos*)num2;
  if (a -> age > b -> age)
  {
	  return 1;
  }
  else if (a -> age < b -> age)
  {
	  return -1;
  }

}


int main(void)
{
	int num1 = 0;
	
	scanf("%d", &num1);
	pos* ary = (pos*)malloc(sizeof(pos) * 100000);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d %s", &ary[i].age, ary[i].name);
		
	}
	qsort(ary, num1, sizeof(pos), compare);

	for (int i = 0; i < num1; i++)
	{
		printf("%d %s\n", ary[i].age, ary[i].name);
	}

	free(ary);
}