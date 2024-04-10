#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	long long int number;
	long long int time;
	long long int sumtime;
	long long int counter;
}info;
info list[100005];
typedef struct Heap
{
	int size;
	info heap[100005];
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}
void init(Heap* h)
{
	h->size = 0;
}
void swap(info* num1, info* num2)
{
	info temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void insert(Heap* h, info num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size].sumtime < h->heap[size / 2].sumtime)
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
void insertmax(Heap* h, info num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size].counter > h->heap[size / 2].counter)
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
info deletemax(Heap* h)
{
	info root = h->heap[1];
	int parent = 1;
	int child = 2;
	info temp = h->heap[h->size--];
	h->heap[1] = temp;
	while (child <= h->size)
	{
		if (child < h->size && h->heap[child].counter < h->heap[child + 1].counter)
		{
			child++;
		}
		if (temp.counter >= h->heap[child].counter)
		{
			break;
		}
		swap(&h->heap[parent], &h->heap[child]);
		parent = child;
		child *= 2;
	}
	return root;
}
info delete (Heap* h)
{
	info root = h->heap[1];
	int parent = 1;
	int child = 2;
	info temp = h->heap[h->size--];
	h->heap[1] = temp;
	while (child <= h->size)
	{
		if (child < h->size && h->heap[child].sumtime > h->heap[child + 1].sumtime)
		{
			child++;
		}
		if (temp.sumtime <= h->heap[child].sumtime)
		{
			break;
		}
		swap(&h->heap[parent], &h->heap[child]);
		parent = child;
		child *= 2;
	}
	return root;
}
typedef struct CounterHeap
{
	int size;
	long long int heap[100005];
}CounterHeap;
CounterHeap* createcounter()
{
	return (CounterHeap*)malloc(sizeof(CounterHeap));
}
void initcounter(CounterHeap* h)
{
	h->size = 0;
}
void intswap(long long int* num1, long long int* num2)
{
	long long int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void insertcounter(CounterHeap* h, long long int num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size] < h->heap[size / 2])
	{
		intswap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
long long int deletecounter(CounterHeap* h)
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
		intswap(&h->heap[child], &h->heap[parent]);
		parent = child;
		child *= 2;
	}
	return root;
}
long long int ary1[100005] = { 0, };
int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->sumtime > b->sumtime)
	{
		return 1;
	}
	else if (a->sumtime < b->sumtime)
	{
		return -1;
	}
	else
	{
		if (a->counter < b->counter)
		{
			return 1;
		}
		else if (a->counter > b->counter)
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
	long long int num1 = 0;
	long long int num2 = 0;
	scanf("%lld %lld", &num1, &num2);
	Heap* h = create();
	init(h);
	CounterHeap* h1 = createcounter();
	initcounter(h1);
	Heap* maxh = create();
	init(maxh);
	for (long long int i = 0; i < num1; i++)
	{
		scanf("%lld %lld", &list[i].number, &list[i].time);
	}
	for (long long int i = 0; i < num2; i++)
	{
		insertcounter(h1, i + 1);
	}
	long long int index = 0;
	long long int temp = 0;
	long long int index1 = 0;
	long long int result = 0;
	while (index < num1)
	{
		if (h->size >= num2)
		{
			info del1 = delete(h);
			temp = del1.sumtime;

			insertmax(maxh, del1);
			insertcounter(h1, del1.counter);

			while (del1.sumtime == h->heap[1].sumtime && h->size > 0)
			{
				info del = delete(h);
				insertmax(maxh, del);
				insertcounter(h1, del.counter);
			}
			while (maxh->size > 0)
			{
				info del2 = deletemax(maxh);
			//	printf("%lld %lld %lld\n", del2.number, del2.sumtime, del2.counter);
				ary1[index1] = del2.number;
				index1++;
			}
		}
		else
		{
			list[index].sumtime = list[index].time;
			list[index].sumtime += temp;

			list[index].counter = deletecounter(h1);
			
			insert(h, list[index]);
			
			index++;
		}
	}
	qsort(h->heap, h->size + 1, sizeof(info), compare);
	long long int count1 = index1;
	//printf("%lld\n", count1);
	for (long long int i = 0; i < index1; i++)
	{
		result += (i + 1) * ary1[i];
	}
	for (long long int i = 1; i < h->size + 1; i++)
	{
		result += (i + count1)* (h->heap[i].number);
	}
	printf("%lld", result);
}