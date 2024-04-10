#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	int distence;
	int charge;
}info;
info list[10005];
typedef struct Heap
{
	int size;
	int heap[10005];
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
	int temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}
void insert(Heap* h, int num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size] > h->heap[size / 2])
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
int delete(Heap* h)
{
	int root = h->heap[1];
	int parent = 1;
	int child = 2;
	int temp = h->heap[h->size--];
	h->heap[1] = temp;
	while (child <= h->size)
	{
		if (child < h->size && h->heap[child] < h->heap[child + 1])
		{
			child++;
		}
		if (temp >= h->heap[child])
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
	if (a->distence > b->distence)
	{
		return 1;
	}
	else if (a->distence < b->distence)
	{
		return -1;
	}
	else
	{
		if (a->charge < b->charge)
		{
			return 1;
		}
		else if (a->charge > b->charge)
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
		scanf("%d %d", &list[i].distence, &list[i].charge);
	}
	int end = 0;
	int temp = 0;
	scanf("%d %d", &end, &temp);
	qsort(list, num1, sizeof(info), compare);
	int index = 0;
	int result = 0;
	while (index < num1)
	{
		if (temp >= end)
		{
			printf("%d", result);
			return 0;
		}
		if (temp >= list[index].distence)
		{
			insert(h, list[index].charge);
			index++;
		}
		else
		{
			while (temp < list[index].distence)
			{
				if (h->size > 0)
				{
					temp += delete(h);
					result++;
				}
				else
				{
					printf("-1", temp);
					return 0;
				}	
			}
			insert(h, list[index].charge);
			index++;
		}
	}
	while (temp < end)
	{
		if (h->size == 0)
		{
			break;
		}
		else
		{
			temp += delete(h);
			result++;
		}
	}
	if (temp >= end)
	{
		printf("%d", result);
	}
	else
	{
		printf("-1");
	}
}