#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	long long int number;
	int count;
}info;
info list[100005];
info list1[100005];

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;

	if (a -> number > b -> number)
	{
		return 1;
	}
	else if (a ->number < b->number)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int lower_bound(info* ary, int size, long long int key)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (ary[cen].number >= key)
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
int upper_bound(info* ary, int size, long long int key)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (ary[cen].number > key)
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

int compare1(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->count > b->count)
	{
		return 1;
	}
	else if (a->count < b->count)
	{
		return -1;
	}
	else
	{
		if (a->number > b->number)
		{
			return -1;
		}
		else if (a->number < b->number)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &list[i].number);
	}
	qsort(list, num1, sizeof(info), compare);

	int index = 0;
	list[num1].number = 6611686018427387904;
	for (int i = 0; i < num1; i++)
	{
		if (list[i].number != list[i + 1].number)
		{
			list1[index].number = list[i].number;
			index++;
		}
		
	}
	for (int i = 0; i < index; i++)
	{
		int result = upper_bound(list, num1, list1[i].number) - lower_bound(list, num1, list1[i].number);
		if (i == index - 1)
		{
			result++;
			list1[i].count = result;
		}
		else
		{
			list1[i].count = result;
		}
		//printf("%lld %d\n", list1[i].number, list1[i].count);

	}
	qsort(list1, index, sizeof(info), compare1);
	for (int i = 0; i < index; i++)
	{
		//printf("%lld %d\n", list1[i].number, list1[i].count);
	}
	printf("%lld", list1[index - 1].number);
}