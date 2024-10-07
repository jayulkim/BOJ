#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int compare(const void* num1, const void* num2) 
{
  int a = *(long long int*)num1;
  int b = *(long long int*)num2;
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
	long long int num2 = 1000000000;
	int num3 = 0;
	long long int* ary1 = (long long int*)malloc(sizeof(long long int) * 1000000);
	long long int* ary2 = (long long int*)malloc(sizeof(long long int) * 1000000);
	
	int num4 = 0;
	int num5 = 0;

	int count = 1;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary1[i]);

	}
	qsort(ary1, num1, sizeof(long long int), compare);
	for (int i = 1; i < num1; i++)
	{
		if (ary1[i] - ary1[i - 1] <= num2)
		{
			num2 = ary1[i] - ary1[i - 1];
		}
	}
	if (num2 != 1)
	{
		ary2[0] = num2;
		for (int i = 2; i <= num2 / 2; i++)
		{
			if (num2 % i == 0)
			{
				ary2[count] = i;
				count++;
			}
		}

		qsort(ary2, count, sizeof(long long int), compare);

		for (int i = count - 1; i >= 0; i--)
		{
			int count1 = 0;
			for (int j = 0; j < num1 - 1; j++)
			{
				num3 = ary1[num1 - 1] % ary2[i];

				if (ary1[j] % ary2[i] != num3)
				{
					count1++;
					break;
				}
			}
			if (count1 == 0)
			{
				num4 = ary2[i];
				break;
			}
		}

		if (num4 == 0)
		{
			printf("%lld", ary1[num1 - 1] - ary1[0] + 1 - num1);
		}
		else if (num4 != 0)
		{
			for (int i = 0; i <= (ary1[num1 - 1] - ary1[0]) / num4; i++)
			{
				num5++;
			}
			printf("%lld", num5 - num1);
		}
	}
	else if (num2 == 1)
	{
		printf("%lld", ary1[num1 - 1] - ary1[0] + 1 - num1);
	}
	
	
	
	free(ary1);
	free(ary2);

}

	 
