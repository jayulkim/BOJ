#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* link;
}Node;

Node* graph[101];

Node* insert(Node* head, int num)
{
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = num;
    new->link = head;
    head = new;
    return head;
}
void insertgraph(int start, int end)
{
    graph[start] = insert(graph[start], end);
    graph[end] = insert(graph[end], start);
}
int ary[101] = { 0, };
int count = 0;
void dfs(int start)
{
    ary[start] = 1;
    for (Node* i = graph[start]; i != NULL; i = i->link)
    {
        if (ary[i->data] == 0)
        {        
            count++;
            ary[i->data] = 1;
            dfs(i->data);
        }
    }
}

int main(void)
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d", &num1);
    scanf("%d", &num2);
    for (int i = 0; i < num2; i++)
    {
        int start = 0;
        int end = 0;
        scanf("%d %d", &start, &end);
        insertgraph(start, end);
    }
    dfs(1);
    printf("%d", count);
}