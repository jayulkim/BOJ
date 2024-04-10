#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct info
{
	int start;
	int end;
	int number;
}info;

typedef struct Heap
{
	int size;
	info heap[100005];
}Heap;
Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}
void init(Heap* h)
{
	h->size = 0;
}
void swap(info* num1, info* num2)
{
	info temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void insert(Heap* h, info num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size].end < h->heap[size / 2].end)
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
void insertnumber(Heap* h, info num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size].number < h->heap[size / 2].number)
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
info deletenumber(Heap* h)
{
	info root = h->heap[1];
	int parent = 1;
	int child = 2;
	info temp = h->heap[h->size--];
	h->heap[1] = temp;
	while (child <= h->size)
	{
		if (child < h->size && h->heap[child].number > h->heap[child + 1].number)
		{
			child++;
		}
		if (temp.number <= h->heap[child].number)
		{
			break;
		}
		swap(&h->heap[child], &h->heap[parent]);
		parent = child;
		child *= 2;
	}
	return root;
}
info delete(Heap* h)
{
	info root = h->heap[1];
	int parent = 1;
	int child = 2;
	info temp = h->heap[h->size--];
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
	return root;
}
info list[100005];
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
}
int ary[100005] = { 0, };
int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d", &list[i].start, &list[i].end);
	}
	qsort(list, num1, sizeof(info), compare);
	Heap* h = create();
	init(h);
	Heap* minnumberheap = create();
	init(minnumberheap);
	list[0].number = 1;
	insert(h, list[0]);
	ary[1]++;
	int count = 2;
	for (int i = 1; i < num1; i++)
	{
		while (h->heap[1].end <= list[i].start && h->size >= 1)
		{
			insertnumber(minnumberheap, delete(h));
		}
		if (minnumberheap->size == 0)
		{
			list[i].number = count;
			ary[list[i].number]++;
			insert(h, list[i]);
			count++;
		}
		else
		{
			if (minnumberheap->size > 0)
			{
				list[i].number = deletenumber(minnumberheap).number;
			}
			ary[list[i].number]++;
			insert(h, list[i]);
		}
	}
	while (minnumberheap->size > 0)
	{
		info del = deletenumber(minnumberheap);
		//ary[del.number]++;
		insert(h, del);
	}
	printf("%d\n", h->size);
	for (int i = 1; i <= h->size; i++)
	{
		printf("%d ", ary[i]);
	}
}