#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	int num;
	int number;
	int index;
	int start;
	int end;
}info;
info list[100005] = { 0, };
typedef struct info1
{
	int number;
	int end;
}info1;
typedef struct Heap
{
	int size;
	info1 heap[100005];
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}
void init(Heap* h)
{
	h->size = 0;
}
void swap(info1* num1, info1* num2)
{
	info1 temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void insert(Heap* h, int end, int number)
{
	int size = ++(h->size);
	h->heap[size].end = end;
	h->heap[size].number = number;
	while (size != 1 && h->heap[size].end < h->heap[size / 2].end)
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}

void delete(Heap* h)
{
	int parent = 1;
	int child = 2;
	info1 root = h->heap[1];
	info1 temp = h->heap[h->size--];
	h->heap[1] = temp;
	while (child <= h->size)
	{
		if (child < h->size && h->heap[child].end > h->heap[child + 1].end)
		{
			child++;
		}
		if (temp.end <= h->heap[child].end)
		{
			break;
		}
		swap(&h->heap[child], &h->heap[parent]);
		parent = child;
		child *= 2;
	}
}

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->start > b->start)
	{
		return 1;
	}
	else if (a->start < b->start)
	{
		return -1;
	}
	else
	{
		if (a->end < b->end)
		{
			return 1;
		}
		else if (a->end > b->end)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}
int compare1(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	return a->num - b->num;
}
int main(void)
{
	Heap* h = create();
	init(h);
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d %d",&list[i].num, & list[i].start, &list[i].end);
		list[i].index = i;
	}
	qsort(list, num1, sizeof(info), compare);
	insert(h, list[0].end, 1);
	int count = 1;
	list[0].number = count;
	for (int i = 1; i < num1; i++)
	{
		if (list[i].start < h->heap[1].end)
		{
			count++;
			insert(h, list[i].end, count);
			list[i].number = count;
		}
		else
		{
			int temp = h->heap[1].number;
			list[i].number = temp;
			delete(h);
			insert(h, list[i].end, temp);
		}
	}
	printf("%d\n", h->size);
	qsort(list, num1, sizeof(info), compare1);
	for (int i = 0; i < num1; i++)
	{
		printf("%d\n", list[i].number);
	}
}