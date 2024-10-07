#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Heap
{
	int size;
	int heap[100005];
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
	h->heap[++(h->size)] = num;
	int size = h->size;
	while (size != 1)
	{
		if (abs(h->heap[size]) < abs(h->heap[size / 2]))
		{
			swap(&h->heap[size], &h->heap[size / 2]);
			size /= 2;
		}
		else if (abs(h->heap[size]) == abs(h->heap[size / 2]))
		{
			if (h->heap[size] < h->heap[size / 2])
			{
				swap(&h->heap[size], &h->heap[size / 2]);
				size /= 2;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
		
}
int delete(Heap* h)
{
	int root = h->heap[1];
	int parent = 1;
	int child = 2;
	h->heap[1] = h->heap[(h->size)--];
	while (child <= h->size)
	{
		if (child < h->size && abs(h->heap[child]) > abs(h->heap[child + 1]))
		{
			child++;
		}
		else if (child < h->size && abs(h->heap[child]) == abs(h->heap[child + 1]))
		{
			if (h->heap[child] > h->heap[child + 1])
			{
				child++;
			}
		}
		if (abs(h->heap[parent]) > abs(h->heap[child]))
		{
			swap(&h->heap[parent], &h->heap[child]);
			parent = child;
			child *= 2;
		}
		else if (abs(h->heap[parent]) == abs(h->heap[child]))
		{
			if (h->heap[parent] > h->heap[child])
			{
				swap(&h->heap[parent], &h->heap[child]);
				parent = child;
				child *= 2;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	return root;
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	Heap* h = create();
	init(h);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		if (num2 == 0)
		{
			if (h->size == 0)
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", delete(h));
			}
		}
		else
		{
			insert(h, num2);
		}
	}
}