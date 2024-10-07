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

	int ary1[100] = { 0, };

	int* ary2 = (int*)malloc(sizeof(int) * 10000000);

	int count = 0;
	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary1[i]);
	}
	for (int i = 0; i < num1 - 2; i++)
	{
		for (int j = i + 1; j < num1 - 1; j++)
		{
			for (int k = j + 1; k < num1; k++)
			{
				if (ary1[i] + ary1[j] + ary1[k] - num2 <= 0)
				{
					ary2[count] = ary1[i] + ary1[j] + ary1[k] - num2;
					count++;
				}	
			}
		}
	}
	qsort(ary2, count, sizeof(int), compare);

	printf("%d", num2 + ary2[count - 1]);
	free(ary2);
}
	
