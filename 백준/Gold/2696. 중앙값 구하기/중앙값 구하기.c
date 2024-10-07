#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void mininsert(Heap* h, int num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size]< h->heap[size / 2])
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}

int mindelete(Heap* h)
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
void maxinsert(Heap* h, int num)
{
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size] > h->heap[size / 2])
	{
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
int maxdelete(Heap* h)
{
	int parent = 1;
	int child = 2;
	int root = h->heap[1];
	int temp = h->heap[h->size--];
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
		swap(&h->heap[child], &h->heap[parent]);
		parent = child;
		child *= 2;
	}
	return root;
}
int ary[10005] = { 0, };

int main(void)
{	
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		Heap* minh = create();
		init(minh);
		Heap* maxh = create();
		init(maxh);

		int index = 0;
		int num1 = 0;
		scanf("%d", &num1);
		for (int j = 0; j < num1; j++)
		{
			int num2 = 0;
			scanf("%d", &num2);
			if (j == 0)
			{
				maxinsert(maxh, num2);
				ary[index] = maxh->heap[1];
				index++;
			}
			else
			{
				if (j % 2 == 0)
				{
					if (num2 >= maxh->heap[1])
					{
						mininsert(minh, num2);
						while ((minh->size) + 1 > maxh->size)
						{
							maxinsert(maxh, mindelete(minh));
						}
						while ((minh->size) + 1 < maxh->size)
						{
							mininsert(minh, maxdelete(maxh));
						}
						ary[index] = maxh->heap[1];
						index++;
					}
					else
					{
						maxinsert(maxh, num2);
						while ((minh->size) + 1 > maxh->size)
						{
							maxinsert(maxh, mindelete(minh));
						}
						while ((minh->size) + 1 < maxh->size)
						{
							mininsert(minh, maxdelete(maxh));
						}
						ary[index] = maxh->heap[1];
						index++;
					}
				}
				else
				{
					if (num2 >= maxh->heap[1])
					{
						mininsert(minh, num2);
						while ((minh->size) > maxh->size)
						{
							maxinsert(maxh, mindelete(minh));
						}
						while ((minh->size)< maxh->size)
						{
							mininsert(minh, maxdelete(maxh));
						}
					}
					else
					{
						maxinsert(maxh, num2);
						while ((minh->size) > maxh->size)
						{
							maxinsert(maxh, mindelete(minh));
						}
						while ((minh->size) < maxh->size)
						{
							mininsert(minh, maxdelete(maxh));
						}
					}
				}
			}
		}
		printf("%d\n", index);
		for (int j = 0; j < index; j++)
		{
			if (j % 10 == 0 && j != 0)
			{
				printf("\n");
			}
			printf("%d ", ary[j]);
		}
		printf("\n");
	}
}