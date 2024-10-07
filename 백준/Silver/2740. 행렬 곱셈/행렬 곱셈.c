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
	int num2 = 1;

	int num3 = 0;
	int num4 = 0;


	scanf("%d %d", &num1, &num2);

	int ary1[100][100] = {0,};
	int ary2[100][100] = {0,};
	int ary3[100][100] = { 0, };

	
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			scanf("%d", &ary1[i][j]);
		}
	}
	scanf("%d %d", &num3, &num4);

	for (int i = 0; i < num3; i++)
	{
		for (int j = 0; j < num4; j++)
		{
			scanf("%d", &ary2[i][j]);
		}
	}
	for (int i = 0; i < num1; i++)
	{
		
		for (int k = 0; k < num4; k++)
		{
			int count = 0;
			for (int j = 0; j < num2; j++)
			{
				count += ary1[i][j] * ary2[j][k];
			}
			ary3[i][k] = count;
		}	
		
	}
	for (int i = 0; i < num1; i++)
	{

		for (int k = 0; k < num4; k++)
		{
			printf("%d ", ary3[i][k]);
		}
		printf("\n");
	}
}
	
