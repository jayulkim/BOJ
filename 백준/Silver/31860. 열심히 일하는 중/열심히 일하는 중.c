#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
	int size;
	int heap[100001];
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
	int i = ++(h->size);
	h->heap[i] = num;
	while (i != 1 && h->heap[i] > h->heap[i / 2])
	{
		swap(&h->heap[i], &h->heap[i / 2]);
		i /= 2;
	}
}
int delete(Heap* h)
{
	int root = h->heap[1];
	int temp = h->heap[h->size--];
	h->heap[1] = temp;
	int parent = 1;
	int child = 2;
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
		swap(&h->heap[parent], &h->heap[child]);
		parent = child;
		child *= 2;
	}
	return root;
}
int ary[10000001] = { 0, };
int index = 0;
int main(void)
{
	int n = 0, m = 0, k = 0;
	scanf("%d %d %d", &n, &m, &k);
	Heap* h = create();
	init(h);
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		scanf("%d", &num);
		insert(h, num);
	}
	int count = 0;
	int pre = 0;
	while (h->heap[1] > k)
	{
		int del = delete(h);
		int temp = pre / 2 + del;
		ary[index++] = temp;
		pre = temp;
		insert(h, del - m);
		count++;
	}
	printf("%d\n", count);
	for (int i = 0; i < index; i++)
	{
		printf("%d\n", ary[i]);
	}
}