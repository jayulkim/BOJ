#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
    long long int start;
    long long int v;
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
    while (size != 1)
    {
        if (h->heap[size].v > h->heap[size / 2].v)
        {
            swap(&h->heap[size], &h->heap[size / 2]);
            size /= 2;
        }
        else if (h->heap[size].v == h->heap[size / 2].v)
        {
            if (h->heap[size].start < h->heap[size / 2].start)
            {
                swap(&h->heap[size], &h->heap[size / 2]);
                size /= 2;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
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
        if (child < h->size)
        {
            if (h->heap[child].v < h->heap[child + 1].v)
            {
                child++;
            }
            else if (h->heap[child].v == h->heap[child + 1].v)
            {
                if (h->heap[child].start > h->heap[child + 1].start)
                {
                    child++;
                }
            }
        }
        if (temp.v > h->heap[child].v)
        {
            break;
        }
        else if (temp.v == h->heap[child].v)
        {
            if (temp.start <= h->heap[child].start)
            {
                break;
            }
        }
        swap(&h->heap[parent], &h->heap[child]);
        parent = child;
        child *= 2;
    }
    return root;
}

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
        if (a->v < b->v)
        {
            return 1;
        }
        else if (a->v > b->v)
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
    for (int j = 0; j < num1; j++)
    {
        int num2 = 0;
        long long int temp = 0;
        scanf("%d %lld", &num2, &temp);
        for (int k = 0; k < num2; k++)
        {
            scanf("%lld", &list[k].start);
        }
        for (int k = 0; k < num2; k++)
        {
            scanf("%lld", &list[k].v);
        }
        long long int result = 0;
        int index = 0;
        qsort(list, num2, sizeof(info), compare);
        while (index < num2)
        {
            if (temp >= list[index].start && index < num2)
            {
                while (temp >= list[index].start && index < num2)
                {
                    insert(h, list[index]);
                    index++;
                }
            }
            else if (temp < list[index].start && index < num2)
            {
                while (h->size > 0 && temp < list[index].start)
                {
                    info del = delete(h);
                    result += (temp - del.start) * del.v;
                    temp++;
                }
                temp = list[index].start;
                insert(h, list[index]);
                index++;
            }           
        }
        while (h->size > 0)
        {
            info del = delete(h);
            result += (temp - del.start) * del.v;
            temp++;
            if (temp >= list[index].start && index < num2)
            {
                insert(h, list[index]);
                index++;
            }
        }
        printf("%lld\n", result);
        h->size = 0;
    }
}