#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

	int result = 0;
	int ary1[10] = {0,};
	int ary2[10] = { 0, };

	int ary3[10] = { 0, };

	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d %d", &num1, &num2);
		ary1[i] = num1;
		ary2[i] = num2;
	}
	for (int i = 0; i < 10; i++)
	{
		result += ary2[i] - ary1[i];
		ary3[i] = result;
	}
	qsort(ary3, 10, sizeof(int), compare);

	printf("%d", ary3[9]);

	

}
	
