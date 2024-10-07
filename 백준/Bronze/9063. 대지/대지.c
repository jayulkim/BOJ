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
	int num1 = 0; 
	int num2 = 0;

	int num3 = 0;
	int ary1[100000] = { 0, };
	int ary2[100000] = { 0, };
	scanf("%d", &num3);

	for (int i = 0; i < num3; i++)
	{
		scanf("%d %d", &num1, &num2);
		ary1[i] = num1;
		ary2[i] = num2;
	}
	qsort(ary1, num3, sizeof(int), compare);
	qsort(ary2, num3, sizeof(int), compare);

	printf("%d", (ary1[num3 - 1] - ary1[0]) * (ary2[num3 - 1] - ary2[0]));
}