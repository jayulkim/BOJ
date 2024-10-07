#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	int rank;
	long long int start;
	long long int end;
	long long int time;
}info;

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
	while (size != 1 && h->heap[size].rank < h->heap[size / 2].rank)
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
info deleterank(Heap* h)
{
	info root = h->heap[1];
	int parent = 1;
	int child = 2;
	info temp = h->heap[h->size--];
	h->heap[1] = temp;
	while (child <= h->size)
	{
		if (child < h->size && h->heap[child].rank > h->heap[child + 1].rank)
		{
			child++;
		}
		if (temp.rank <= h->heap[child].rank)
		{
			break;
		}
		swap(&h->heap[child], &h->heap[parent]);
		parent = child;
		child *= 2;
	}
	return root;
}
info list[100005];
int compare(const void* num1, const void* num2)
{
	info* a = (info*)num1;
	info* b = (info*)num2;
	if (a->start > b->start)
	{
		return 1;
	}
	else if (a->start < b->start)
	{
		return -1;
	}
	else
	{
		if (a->rank > b->rank)
		{
			return 1;
		}
		else if (a->rank < b->rank)
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
	for (int i = 0; i < num1; i++)
	{
		long long int num2 = 0;
		scanf("%lld %lld", &list[i].start, &list[i].time);
		list[i].end = list[i].start + list[i].time;
		list[i].rank = i + 1;
	}
	qsort(list, num1, sizeof(info), compare);
	for (int i = 0; i < num1; i++)
	{
	//	printf("%lld %lld %d\n", list[i].start, list[i].end, list[i].rank);
	}
	long long int result = 0;
	long long int maxend = 0;
	Heap* rankh = create();
	init(rankh);
	maxend = list[0].end;
//	printf("%lld\n", maxend);
	int index = 1;
	while (1)
	{	
		if (maxend >= list[index].start && index < num1)
		{
			while (maxend >= list[index].start && index < num1)
			{
				insert(rankh, list[index]);
				index++;
			}
			if (rankh->size > 0)
			{
				info del = deleterank(rankh);
				if (del.start < maxend)
				{
				//	printf("%lld\n", maxend - del.start);
					if (result < maxend - del.start)
					{
						result = maxend - del.start;
					}
					maxend += del.time;
				}
				else
				{
					maxend = del.end;
				}
			}
		}
		else if (maxend < list[index].start && index < num1)
		{	
			if (rankh->size == 0)
			{
				while (maxend < list[index].start && index < num1)
				{
					maxend = list[index].end;
					//printf("%lld\n", maxend);
					index++;
				}
				while (maxend >= list[index].start && index < num1)
				{
					insert(rankh, list[index]);
					index++;
				}
			}
			else
			{
				if (rankh->size > 0)
				{
					info del = deleterank(rankh);
					if (del.start < maxend)
					{
					//	printf("%lld\n", maxend - del.start);
						if (result < maxend - del.start)
						{
							result = maxend - del.start;
						}
						maxend += del.time;
					}
					else
					{
						maxend = del.end;
					}
				}
			}
		}
		
		if (index >= num1)
		{
			if (rankh->size > 0)
			{
				info del = deleterank(rankh);
				if (del.start < maxend)
				{
				//	printf("%lld\n", maxend - del.start);
					if (result < maxend - del.start)
					{
						result = maxend - del.start;
					}
					maxend += del.time;
				}
				else
				{
					maxend = del.end;
				}
			}
			else
			{
				break;
			}
		}
	}
	printf("%lld", result);
}