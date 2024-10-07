#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary1[100000] = { 0, };
int sum1[100000] = { 0, };
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

	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary1[i]);
	}

	for (int i = 0; i < num2; i++)
	{
		sum1[0] += ary1[i];
	}
	
	for (int i = 0; i < num1 - num2; i++)
	{
		sum1[i + 1] =  sum1[i] + ary1[i + num2] - ary1[i];

	}
	qsort(sum1, num1 - num2 + 1, sizeof(int), compare);
	printf("%d\n", sum1[num1 - num2]);
}