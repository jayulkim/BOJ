#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
void mininsert(Heap* h, int num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size]< h->heap[size / 2])
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}

int mindelete(Heap* h)
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
	return root;
}
void maxinsert(Heap* h, int num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size] > h->heap[size / 2])
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
int maxdelete(Heap* h)
{
	int parent = 1;
	int child = 2;
	int root = h->heap[1];
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

int main(void)
{
	Heap* minh = create();
	init(minh);
	Heap* maxh = create();
	init(maxh);
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		if (i == 0)
		{
			maxinsert(maxh, num2);
			printf("%d\n", maxh->heap[1]);
		}
		else
		{
			if (num2 >= maxh->heap[1])
			{
				mininsert(minh, num2);
				if (i % 2 == 1)
				{
					while (minh->size > maxh->size)
					{
						maxinsert(maxh, mindelete(minh));
					}
					while (minh->size < maxh->size)
					{
						mininsert(minh, maxdelete(maxh));
					}
				}
				else
				{
					while ((minh->size) + 1 > maxh->size)
					{
						maxinsert(maxh, mindelete(minh));
					}
					while ((minh->size) + 1 < maxh->size)
					{
						mininsert(minh, maxdelete(maxh));
					}
				}
				printf("%d\n", maxh->heap[1]);
			}
			else
			{
				maxinsert(maxh, num2);
				if (i % 2 == 1)
				{
					while (minh->size > maxh->size)
					{
						maxinsert(maxh, mindelete(minh));
					}
					while (minh->size < maxh->size)
					{
						mininsert(minh, maxdelete(maxh));
					}
				}
				else
				{
					while ((minh->size) + 1 > maxh->size)
					{
						maxinsert(maxh, mindelete(minh));
					}
					while ((minh->size) + 1 < maxh->size)
					{
						mininsert(minh, maxdelete(maxh));
					}
				}
				printf("%d\n", maxh->heap[1]);
			}
		}
	}
}