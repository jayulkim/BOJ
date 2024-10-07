#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct pos
{
	int x;
	int y;
}pos;

pos list[1000000];

pos list1[500000];
pos list2[500000];

int compareXY(const void* num1, const void* num2)
{
	pos* a = (pos*)num1;
	pos* b = (pos*)num2;

	if (a->x > b->x)
	{
		return 1;
	}
	else if (a->x < b->x)
	{
		return -1;
	}
	else
	{
		if (a->y > b->y)
		{
			return 1;
		}
		else if (a->y < b->y)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}

int search(pos* arr, int size, int x, int y)
{
	int start = 0, end = size - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid].x == x && arr[mid].y == y)
		{
			return mid;
		}
		else if (arr[mid].x < x || (arr[mid].x == x && arr[mid].y < y))
		{
			start = mid + 1;
		}	
		else
		{
			end = mid - 1;
		}
			
	}
	return -1;
}
int main(void)
{
	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num2; i++)
	{
		scanf("%d %d", &list[i].x, &list[i].y);
	}

	int index = 0;
	for (int i = 0; i < num2; i++)
	{
		if (list[i].x - 2 > 0)
		{
			list1[index].x = list[i].x - 2;
			list1[index].y = list[i].y;
			index++;
		}
		if (list[i].y - 2 > 0)
		{
			list1[index].x = list[i].x;
			list1[index].y = list[i].y - 2;
			index++;
		}
		if (list[i].x + 2 <= num1)
		{
			list1[index].x = list[i].x + 2;
			list1[index].y = list[i].y;
			index++;
		}
		if (list[i].y + 2 <= num1)
		{
			list1[index].x = list[i].x;
			list1[index].y = list[i].y + 2;
			index++;
		}

	}
	
	qsort(list1, index, sizeof(pos), compareXY);

	int index2 = 0;
	for (int i = 0; i < index; i++)
	{
		if (list1[i].x != list1[i + 1].x || list1[i].y != list1[i + 1].y)
		{
			list2[index2].x = list1[i].x;
			list2[index2].y = list1[i].y;
			index2++;
		}
		
	}
	
	int result = 0;
	qsort(list, num2, sizeof(pos), compareXY);
	
	for (int i = 0; i < index2; i++)
	{
		int result = search(list, num2, list2[i].x, list2[i].y);
		if (result != -1)
		{
			list2[i].x = 0;
			list2[i].y = 0;
		}
	}

	for (int i = 0; i < index2; i++)
	{
		if (list2[i].x != 0 && list2[i].y != 0)
		{
			result++;
		}
	}
	printf("%d\n", result);
}