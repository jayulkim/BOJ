#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <memory.h>

int visited[1000001];

typedef struct queue

{

    int size;

    int front;

    int back;

    int* q;

}queue;

queue* create(int size)

{

    queue* new = (queue*)malloc(sizeof(queue));

    new->front = 0;

    new ->back = 0;

    new ->size = size + 1;

    new->q = (int*)malloc(sizeof(int)*new->size);

    return new;

}

int empty(queue* q)

{

    if (q->front == q->back)

    {

        return 1;

    }

    else

    {

        return 0;

    }

}

void push(queue* q, int num)

{

    q->back = (q->back + 1 + q->size) % q->size;

    q->q[q->back] = num;

}

int pop(queue* q)

{

    q->front = (q->front + 1 +q->size)%q->size;

    return q->q[q->front];

}

int result = 0;

void bfs(int f, int start, int end, int up, int down)

{

    queue* q1 = create(1000001);

    queue* q2 = create(1000001);

    push(q1, start);

    visited[start]=1;

    while(1)

    {

        if (empty(q2)==1 && empty(q1)==1)

        {

            printf("use the stairs");

            return;

        }

        while(empty(q1) == 0)

        {

            int temp = pop(q1);

            if (temp == end)

            {

                printf("%d", result);

                return;

            }

            visited[temp]=1;

            if(temp + up <= f && visited[temp + up]== 0)

            {

                push(q2, temp + up);

                visited[up + temp]=1;

            }

            if (temp - down >= 1 && visited[temp - down]==0)

            {

                push(q2,temp-down);

                visited[temp - down]=1;

            }

        }

        result++;

        while(empty(q2) == 0)

        {

            int temp = pop(q2);

            if (temp == end)

            {

                printf("%d", result);

                return;

            }

            visited[temp]=1;

            if(temp + up <= f && visited[temp + up]== 0)

            {

                push(q1, temp + up);

                visited[up + temp]=1;

            }

            if (temp - down >= 1 && visited[temp - down]==0)

            {

                push(q1,temp-down);

                visited[temp - down]=1;

            }

        }

        result++;

    }

}

int main(void)

{

    int f =0,start=0,end=0,up=0,down=0;

    scanf("%d %d %d %d %d", &f, &start, &end, &up, &down);

    bfs(f, start, end, up, down);

}