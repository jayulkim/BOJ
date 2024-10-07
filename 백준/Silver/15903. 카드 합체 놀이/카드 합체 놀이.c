#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
	int size;
	long long int heap[1001];
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
long long int delete(Heap* h)
{
	int parent = 1;
	int child = 2;
	long long int root = h->heap[1];
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
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	long long int sum = 0;
	Heap* h = create();
	init(h);
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1; i++)
	{
		long long int num3 = 0;
		scanf("%lld", &num3);
		insert(h, num3);
	}
	for (int i = 0; i < num2; i++)
	{
		long long int num4 = delete(h);
		long long int num5 = delete(h);
		insert(h, num4 + num5);
		insert(h, num4 + num5);
	}
	while (h->size > 0)
	{
		sum += delete(h);
	}
	printf("%lld", sum);
}