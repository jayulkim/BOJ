#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[200001] = { 0, };

typedef struct Heap
{
	int size;
	long long int heap[200001];
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

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	Heap* h = create();
	init(h);
	long long int max = 0;
	for (int i = 0; i < num1;i++)
	{
		scanf("%d", &ary[i]);
		insert(h, ary[i]);
		if (max < ary[i])
		{
			max = ary[i];
		}
	}
	long long int min = max;
	long long int result = 1000000001LL;
	while (1)
	{
		long long int del = delete(h);
		if (del > min)
		{
			printf("%lld", result);
			break;
		}
		if (max - del < result)
		{
			result = max - del;
		}
		if (max < del * 2)
		{
			max = del * 2;
		}
		insert(h, del * 2);
	}
}