#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[10000] = { 0, }; // 순서기억 배열
int ary1[10000] = { 0, };

int ary2[10000] = { 0, }; //중복제거한 배열
//구조체로 수정
//값
//빈도수

typedef struct info
{
	int number;
	int count;
	int index;
}info;

info list[10000];

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
int compare1(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->count > b->count)
	{
		return -1;
	}
	else if (a->count < b->count)
	{
		return 1;
	}
	else
	{
		if (a->index > b->index)
		{
			return 1;
		}
		else if (a->index < b->index)
		{
			return -1;
		}
	}
}
int compare2(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->number> b->number)
	{
		return 1;
	}
	else if (a->number< b->number)
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
int lower_bound1(info* ary, int size, int key)
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

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		ary1[i] = ary[i];
		ary2[i] = ary[i];
	}
	qsort(ary1, num1, sizeof(int), compare);
	int index = 0;
	for (int i = 0; i < num1; i++)
	{
		if (ary1[i] != ary1[i + 1])
		{
			list[index].number = ary1[i];
			//printf("%d ", list[index].number);
			index++;
		}
	}

	for (int i = 0; i < index; i++)
	{
		int result = upper_bound(ary1, num1, list[i].number) - lower_bound(ary1, num1, list[i].number);
		if (i == index - 1)
		{
			list[i].count = result + 1;
		}
		else
		{
			list[i].count = result;
		}
		//printf("%d ", list[i].count);
	}


	for (int i = 0; i < index; i++)
	{
		//printf("%d ", list[i].number);
	}
	
	int count1 = 0;
	qsort(list, index, sizeof(info), compare2);
	for (int i = 0; i < num1; i++)
	{
		if (ary2[i] != 0)
		{
			int result1 = lower_bound1(list, index, ary2[i]);
			list[result1].index = count1;
			for (int j = 0; j < num1; j++)
			{
				if (ary2[j] == list[result1].number)
				{
					ary2[j] = 0;
				}
				
			}
			count1++;
		}
		for (int j = 0; j < num1; j++)
		{
		//	printf("%d ", ary2[j]);
		}
		//printf("\n");
	}

	qsort(list, index, sizeof(info), compare1);
	for (int i = 0; i < index; i++)
	{
		//printf("%d ", list[i].number);
		for (int j = 0; j < list[i].count; j++)
		{
			printf("%d ", list[i].number);
		}
	}



}