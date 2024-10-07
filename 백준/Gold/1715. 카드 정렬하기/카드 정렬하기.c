#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[100005] = { 0, };

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
	int temp = *num2;
	*num2 = *num1;
	*num1 = temp;
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
int delete(Heap* h)
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
int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}
int main(void)
{
	Heap* h = create();
	init(h);
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, num1, sizeof(int), compare);
	for (int i = 0; i < num1; i++)
	{
		insert(h, ary[i]);
	}
	int result1 = 0;
	for (int i = 0; i < num1 -1; i++)
	{
		int result = 0;
		result += delete(h);
		result += delete(h);
		insert(h, result);
		result1 += result;
	}
	printf("%d", result1);
}