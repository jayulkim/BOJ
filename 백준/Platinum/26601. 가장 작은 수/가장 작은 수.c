#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[2112233] = { 0, };

typedef struct Heap
{
	int size;
	long long int heap[2112233];
}Heap;
Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}
void init(Heap* h)
{
	h->size = 0;
}
void swap(long long int *num1, long long int *num2)
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
	Heap* h = create();
	init(h);
	for (int i = 2; i * i <= 2112222; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 2112222; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	for (long long int i = 2; i <= 2112222; i++)
	{
		if (ary[i] == 0)
		{
			insert(h, i);
		}
	}
	int num1 = 0;
	scanf("%d", &num1);
	long long int result = 1;
	for (int i = 0; i < num1; i++)
	{
		long long int del = delete(h);
		result *= (del % 2000003LL);
		result %= 2000003LL;
		if (del * del <= 9223372036854775806LL)
		{
			insert(h, del * del);
		}
	}
	printf("%lld", result % 2000003LL);
}