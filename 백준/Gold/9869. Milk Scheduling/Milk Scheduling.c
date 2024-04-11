#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct info
{
	long long int score;
	long long int time;
}info;
info list[10005];
typedef struct Heap
{
	int size;
	long long int heap[10005];
}Heap;

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
int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->time > b->time)
	{
		return 1;
	}
	else if (a->time < b->time)
	{
		return -1;
	}
	else
	{
		if (a->score < b->score)
		{
			return 1;
		}
		else if (a->score > b->score)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}
int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	Heap* h = (Heap*)malloc(sizeof(Heap));
	init(h);
	for (int i = 0; i < num1; i++)
	{
		scanf("%lld %lld", &list[i].score, &list[i].time);
	}
	qsort(list, num1, sizeof(info), compare);
	long long int result = 0;
	int index = 0;
	long long int temp = 0;
	while (index < num1)
	{
		if (temp < list[index].time)
		{
			temp++;
			insert(h, list[index].score);
		}
		else
		{
			if (h->heap[1] < list[index].score)
			{
				delete(h);
				insert(h, list[index].score);
			}
		}
		index++;
	}
	while (h->size > 0)
	{
		result += delete(h);
	}
	printf("%lld", result);
}