#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	int mg;
	long long int worth;
}info;
info list[300005];
int bag[300005] = { 0, };

int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->mg > b->mg)
	{
		return 1;
	}
	else if (a->mg < b->mg)
	{
		return -1;
	}
	else
	{
		if (a->worth < b->worth)
		{
			return 1;
		}
		else if (a->worth > b->worth)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}
int compare1(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}
typedef struct Heap
{
	int size;
	long long int heap[300005];
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
	while (size != 1 && h->heap[size] > h->heap[size / 2])
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

int main(void)
{
	Heap* h = create();
	init(h);
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	long long int result = 0;
	for (int i = 0; i < num1; i++)
	{
		scanf("%d %lld",&list[i].mg, &list[i].worth);
	}
	qsort(list, num1, sizeof(info), compare);
	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &bag[i]);
	}
	qsort(bag, num2, sizeof(int), compare1);
	bag[num2] = 100000005;
	list[num1].mg = 100000005;
	int index = 0;
	int index1 = 0;
	while (index <= num2 && index1 <= num1)
	{	
		if (list[index1].mg <= bag[index])
		{
			insert(h, list[index1].worth);
			index1++;
		}
		else
		{
			if (h->size > 0)
			{
				result += delete(h);
			}
			index++;
		}
	}
	printf("%lld\n", result);
}