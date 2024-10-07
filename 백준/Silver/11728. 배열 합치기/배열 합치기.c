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

int search(long long int* ary, int size, long long int key)
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


int main(void)
{
	

	int num1 = 0;
	int num2 = 0;
	int result = 0;

	int count = 0;
	int count1 = 0;
	scanf("%d %d", &num1, &num2);

	long long int* ary1 = (long long int*)malloc(sizeof(long long int) * 1000000);
	long long int* ary2 = (long long int*)malloc(sizeof(long long int) * 1000000);
	long long int* ary3 = (long long int*)malloc(sizeof(long long int) * 2000000);


	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary1[i]);
	}
	for (int i = 0; i < num2; i++)
	{
		scanf("%lld", &ary2[i]);
	}
	
	for (int i = 0; i < num1; i++)
	{
		ary3[i] = ary1[i];
	}
	for (int i = num1; i < num1 + num2; i++)
	{
		ary3[i] = ary2[i - num1];
	}

	qsort(ary3, num1 + num2, sizeof(long long int), compare);
	for (int i = 0; i < num2 + num1; i++)
	{
		printf("%lld ", ary3[i]);	
	}
	

	free(ary1);
	free(ary2);
	free(ary3);
	return 0;

}