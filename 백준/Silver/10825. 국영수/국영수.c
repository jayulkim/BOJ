#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct pos
{
	char name[150];
	int x;
	int y;
	int z;
}pos;

int compare(const void* num1, const void* num2)
{
  pos* a = (pos*)num1;
  pos* b = (pos*)num2;
  if (a -> x > b -> x)
  {
	  return -1;
  }
  else if (a -> x < b -> x)
  {
	  return 1;
  }
  else
  {
	  if (a->y > b->y)
	  {
		  return 1;
	  }
	  else if (a->y < b->y)
	  {
		  return -1;
	  }
	  else
	  {
		  if (a->z > b->z)
		  {
			  return -1;
		  }
		  else if (a->z < b->z)
		  {
			  return 1;
		  }
		  else
		  {
			  if (strcmp(a->name, b->name) > 0)
			  {
				  return 1;
			  }
			  else if (strcmp(a->name, b->name) < 0)
			  {
				  return -1;
			  }
			  else
			  {
				  return 0;
			  }
		  }
	  }
  }

}


int main(void)
{
	int num1 = 0;

	scanf("%d", &num1);

	pos* ary1 = (pos*)malloc(sizeof(pos) * num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%s %d %d %d", ary1[i].name, &ary1[i].x, &ary1[i].y, &ary1[i].z);
	}
	qsort(ary1, num1, sizeof(pos), compare);
	for (int i = 0; i < num1; i++)
	{
		printf("%s\n", ary1[i].name);
	}

}