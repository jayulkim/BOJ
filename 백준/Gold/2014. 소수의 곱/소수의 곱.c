#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Heap
{
    int size;
    long long int heap[10000005];
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
long long int ary[105] = { 0, };

int main(void)
{
    int num1 = 0;
    int num2 = 0;
    Heap* h = create();
    init(h);
    scanf("%d %d", &num1, &num2);
    for (int i = 0; i < num1; i++)
    {
        scanf("%lld", &ary[i]);
        insert(h, ary[i]);
    }
    int count = 0;
    int count1 = 0;
    long long int num3 = delete(h);
    while (count < num2 - 1)
    {  
        if (h->heap[1] == num3 && h->size > 0)
        {
            while (h->heap[1] == num3 && h->size > 0)
            {
                num3 = delete(h);
            }
        }
        for (int i = 0; i < num1; i++)
        {
            if (num3 < 2147483648 / ary[i])
            {
                insert(h, num3 * ary[i]);
            }
            else
            {
                break;
            }
        }
        num3 = delete(h);
        count++;
    }
    printf("%lld", num3);
}
