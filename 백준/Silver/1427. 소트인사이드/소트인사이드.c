#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
int lower_bound(int* ary, int size, int key)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (ary[cen] >= key)
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return end;
}
int upper_bound(int* ary, int size, int key)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (ary[cen] > key)
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return end;
}

int main(void)
{
	char num1[20];

	scanf("%s", num1);

	int num2 = 0;
	num2 = atoi(num1);

	int ary1[20] = { 0, };
	int count = 0;
	while (num2 >= 1)
	{
		ary1[count] = num2 % 10;
		count++;
		num2 /= 10;
	}
	qsort(ary1, count, sizeof(int), compare);

	for (int i = count - 1; i >= 0; i--)
	{
		printf("%d", ary1[i]);
	}

}
	
