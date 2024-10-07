#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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
int search(int* ary, int size, int key)
{
	int start = 0, end = size - 1;
	while (start <= end) 
	{
		int cen = (start + end) / 2;

		if (ary[cen] == key)
		{
			return cen; 
		}
		else if (ary[cen] > key)
		{
			end = cen - 1;
		}
		else if (ary[cen] < key)
		{
			start = cen + 1;
		}
	}
	return -1; 
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
	int num1 = 0;
	int num2 = 0;

	int* ary1 = (int*)malloc(sizeof(int) * 500000);
	int* ary2 = (int*)malloc(sizeof(int) * 500000);
	
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary1[i]);
	}
	scanf("%d", &num2);

	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &ary2[i]);
	}
	qsort(ary1, num1, sizeof(int), compare);

	for (int j = 0; j < num2; j++)
	{
		int result = 0;
		result = search(ary1, num1, ary2[j]);
		if (result != -1)
		{
			ary2[j] = 1;
		}
		else if (result == -1)
		{
			ary2[j] = 0;
		}
		
	}
	for (int i = 0; i < num2; i++)
	{
		printf("%d ", ary2[i]);
	}
	
}