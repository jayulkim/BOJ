#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct info
{
    int day;
    int score;
}info;
info list[1005];
typedef struct Heap
{
    int size;
    int heap[1005];
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
void insert(Heap* h, int num)
{
    int size = ++(h->size);
    h->heap[size] = num;
    while (size != 1 && h->heap[size] < h->heap[size / 2])
    {
        swap(&h->heap[size], &h->heap[size / 2]);
        size /= 2;
    }
}
int delete(Heap* h)
{
    int root = h->heap[1];
    int parent = 1;
    int child = 2;
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
int compare(const void* num1, const void* num2)
{
    info* a = (info*)num1;
    info* b = (info*)num2;
    if (a->day > b->day)
    {
        return 1;
    }
    else if (a->day < b->day)
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
    Heap* h = create();
    init(h);
    for (int i = 0; i < num1; i++)
    {
        scanf("%d %d", &list[i].day, &list[i].score);
    }
    qsort(list, num1, sizeof(info), compare);
    for (int i = 0; i < num1; i++)
    {
        if (h->size + 1> list[i].day)
        {
            if (h->heap[1] < list[i].score)
            {
                delete(h);
                insert(h, list[i].score);
            }
        }
        else
        {
            insert(h, list[i].score);
        }
    }
    int result = 0;
    while (h->size > 0)
    {
        result += delete(h);
    }
    printf("%d", result);
}
