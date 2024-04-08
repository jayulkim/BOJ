#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
	int size;
	long long int heap[1000005];
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
void insert(Heap* h,long long int num)
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
		swap(&h->heap[parent], &h->heap[child]);
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
	int num1 = 0;
	scanf("%d", &num1);
	Heap* h = create();
	init(h);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		for (int j = 0; j < num2; j++)
		{
			long long int num3 = 0;
			scanf("%lld", &num3);
			insert(h, num3);
		}
		long long int result = 0;
		while (1)
		{
			long long int count = 0;
			long long int count1 = 0;
			count += delete(h);
			count1 += delete(h);
			insert(h, count + count1);
			result += count + count1;
			if (h->size == 1)
			{
				break;
			}
		}
		printf("%lld\n", result);
		h->size = 0;
	}
}