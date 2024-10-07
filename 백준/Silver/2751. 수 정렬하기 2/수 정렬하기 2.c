#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int compare(const void* num1, const void* num2) 
{
  int a = *(int*)num1;
  int b = *(int*)num2;
  if (a > b)
  {
	  return 1;
  }
  else if (a < b)
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
	int num = 0;
	scanf("%d", &num);
	int* ary = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, num, sizeof(int), compare); 
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", ary[i]);
	}
}