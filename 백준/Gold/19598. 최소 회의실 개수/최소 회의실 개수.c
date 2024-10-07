#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	int start;
	int end;
}info;
info list[200005] = { 0, };
typedef struct Heap
{
	int size;
	int heap[200005];
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}
void init(Heap* h)
{
	h->size = 0;
}
void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void insert(Heap* h, int num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size] < h->heap[size / 2])
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}

void delete(Heap* h)
{
	int parent = 1;
	int child = 2;
	int root = h->heap[1];
	int temp = h->heap[h->size--];
	h->heap[1] = temp;
	while (child <= h->size)
	{
		if (child < h->size && h->heap[child] > h->heap[child + 1])
		{
			child++;
		}
		if (temp <= h->heap[child])
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

int main(void)
{
	Heap* h = create();
	init(h);
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d", &list[i].start, &list[i].end);
	}
	qsort(list, num1, sizeof(info), compare);
	insert(h, list[0].end);
	for (int i = 1; i < num1; i++)
	{
		if (list[i].start < h->heap[1])
		{
			insert(h, list[i].end);
		}
		else
		{
			delete(h);
			insert(h, list[i].end);
		}
	}
	printf("%d", h->size);
}