#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct info
{
	int index;
	int number;
}info;
info list[10000005];
typedef struct Heap
{
	int size;
	info heap[10000005];
}Heap;

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
	while (size != 1 && h->heap[size].number < h->heap[size / 2].number)
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
info Delete(Heap* h)
{
	info root = h->heap[1];
	int parent = 1;
	int child = 2;
	info temp = h->heap[h->size--];
	h->heap[1] = temp;
	while (child <= h->size)
	{
		if (child < h->size && h->heap[child].number > h->heap[child + 1].number)
		{
			child++;
		}
		if (temp.number <= h->heap[child].number)
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num1 = 0;
	int num2 = 0;
	Heap* h = (Heap*)malloc(sizeof(Heap));
	init(h);
	cin >> num1 >> num2;
	for (int i = 0; i < num1; i++)
	{
		cin >> list[i].number;
		list[i].index = i;
	}
	for (int i = 0; i < num2; i++)
	{
		insert(h, list[i]);
		cout << h->heap[1].number << ' ';
	}
	for (int i = num2; i < num1; i++)
	{
		while (h->heap[1].index <= i - num2 && h->size > 0)
		{
			Delete(h);
		}
		insert(h, list[i]);
		cout << h->heap[1].number << ' ';
	}
}