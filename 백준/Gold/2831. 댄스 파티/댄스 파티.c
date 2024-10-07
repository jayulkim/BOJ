#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int man[100005] = { 0, };
int woman[100005] = { 0, };

int minusman[100005] = { 0, };
int pluswoman[100005] = { 0, };

int plusman[100005] = { 0, };
int minuswoman[100005] = { 0, };

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}
int compare1(const void* num1, const void* num2)
{
	return *(int*)num2 - *(int*)num1;
}


int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	int index1 = 0;
	int index2 = 0;

	int index3 = 0;
	int index4 = 0;

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &man[i]);
		if (man[i] > 0)
		{
			plusman[index3] = man[i];
			index3++;
		}
		else if (man[i] < 0)
		{
			minusman[index1] = man[i];
			index1++;
		}
	}
	
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &woman[i]);
		if (woman[i] > 0)
		{
			pluswoman[index2] = woman[i];
			index2++;
		}
		else if (woman[i] < 0)
		{
			minuswoman[index4] = woman[i];
			index4++;
		}
	}
	qsort(minusman, index1, sizeof(int), compare1);
	qsort(minuswoman, index4, sizeof(int), compare1);
	qsort(pluswoman, index2, sizeof(int), compare);
	qsort(plusman, index3, sizeof(int), compare);
	int count = 0;
	for (int i = 0; i < index1; i++)
	{
	//	printf("%d ", minusman[i]);
	}
	for (int i = 0; i < index2; i++)
	{
	//	printf("%d ", pluswoman[i]);
	}
	int start = index1 - 1;
	int end = index2 - 1;
	while (start >= 0 && end >= 0)
	{
		if (-minusman[start] > pluswoman[end])
		{
			count++;
			start--;
			end--;
		}
		else
		{
			end--;
		}
	}
	int start1 = index4 - 1;
	int end1 = index3 - 1;
	while (start1 >= 0 && end1 >= 0)
	{
		if (-minuswoman[start1] > plusman[end1])
		{
			count++;
			start1--;
			end1--;
		}
		else
		{
			end1--;
		}
	}


	
	printf("%d", count);
	
}