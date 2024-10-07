#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[20005] = { 0, };

typedef struct Heap
{
	int size;
	long long int heap[20005];
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
	long long int temp = *num2;
	*num2 = *num1;
	*num1 = temp;
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
int compare(const void* num1, const void* num2)
{
	return *(long long int*)num1 - *(long long int*)num2;
}
int main(void)
{
	Heap* h = create();
	init(h);
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%lld", &ary[i]);
	}
	qsort(ary, num1, sizeof(long long int), compare);
	for (int i = 0; i < num1; i++)
	{
		insert(h, ary[i]);
	}
	long long int result1 = 0;
	for (int i = 0; i < num1 -1; i++)
	{
		long long int result = 0;
		result += delete(h);
		result += delete(h);
		insert(h, result);
		result1 += result;
	}
	printf("%lld", result1);
}