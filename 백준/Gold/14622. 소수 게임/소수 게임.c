#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int prime[5000005] = { 0, };
long long int ary[5000005] = { 0, };
typedef struct Heap
{
	int size;
	long long int heap[100005];
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
	long long int root = h->heap[1];
	int parent = 1;
	int child = 2;
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
long long int ary1[5] = { 0, };
int main(void)
{
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2; i <= 5000000; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = 2 * i; j <= 5000000; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	int num1 = 0;
	scanf("%d", &num1);
	long long int result1 = 0;
	long long int result2 = 0;
	Heap* h1 = create();
	init(h1);
	Heap* h2 = create();
	init(h2);
	for (int i = 0; i < num1; i++)
	{
		long long int num2 = 0;
		long long int num3 = 0;
		scanf("%lld %lld", &num2, &num3);
		if (prime[num2] == 0)
		{
			if (ary[num2] == 0)
			{
				insert(h1, num2);
				ary[num2]++;
			}
			else
			{
				result1 -= 1000;
			}
		}
		else
		{
			if (h2->size >= 3)
			{
				ary1[0] = delete(h2);
				ary1[1] = delete(h2);
				ary1[2] = delete(h2);
				result2 += ary1[2];
				insert(h2, ary1[0]);
				insert(h2, ary1[1]);
				insert(h2, ary1[2]);
			}
			else
			{
				result2 += 1000;
			}
		}
		if (prime[num3] == 0)
		{
			if (ary[num3] == 0)
			{
				insert(h2, num3);
				ary[num3]++;
			}
			else
			{
				result2 -= 1000;
			}
		}
		else
		{
			if (h1->size >= 3)
			{
				ary1[0] = delete(h1);
				ary1[1] = delete(h1);
				ary1[2] = delete(h1);
				result1 += ary1[2];
				insert(h1, ary1[0]);
				insert(h1, ary1[1]);
				insert(h1, ary1[2]);
			}
			else
			{
				result1 += 1000;
			}
		}
//		printf("%d %d\n", result1, result2);
	}
	
	if (result1 > result2)
	{
		printf("소수의 신 갓대웅");
	}
	else if (result1 < result2)
	{
		printf("소수 마스터 갓규성");
	}
	else
	{
		printf("우열을 가릴 수 없음");
	}
}