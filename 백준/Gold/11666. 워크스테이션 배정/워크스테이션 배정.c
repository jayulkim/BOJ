#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	long long int start;
	long long int end;
}info;

info list[300005];

typedef struct Heap
{
	int size;
	long long int heap[300005];
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}
void init(Heap* h)
{
	h->size = 0;
}
void swap(long long int* num1, long long int* num2) 
{
	long long int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void insert(Heap* h, long long int num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size] < h->heap[size / 2])
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
long long int Delete(Heap* h)
{
	long long int root = h->heap[1];
	int parent = 1;
	int child = 2;
	long long int temp = h->heap[h->size--];
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
	return root;
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
	int num1 = 0;
	long long int time = 0;
	scanf("%d %lld", &num1, &time);
	for (int i = 0; i < num1; i++)
	{
		long long int num3 = 0;
		scanf("%lld %lld", &list[i].start, &num3);
		list[i].end = list[i].start + num3;
	}
	qsort(list, num1, sizeof(info), compare);
	Heap* h = create();
	init(h);
	insert(h, list[0].end);
	int count = 0;
	int index = 1;
	while (index < num1)
	{
		if (h->size > 0)
		{
			if (h->heap[1] > list[index].start)
			{
				insert(h, list[index].end);
				index++;
			}
			else
			{
				if (list[index].start - h->heap[1] <= time)
				{
					count++;
					Delete(h);
					insert(h, list[index].end);
					index++;
				}
				else
				{
					Delete(h);
				}
			}
		}
		else
		{
			insert(h, list[index].end);
		}
	}
	printf("%d", count);
}