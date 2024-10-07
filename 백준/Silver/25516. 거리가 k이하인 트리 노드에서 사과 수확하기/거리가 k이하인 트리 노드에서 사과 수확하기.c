#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* link;
}Node;
Node* insert(Node* head, int num)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->link = head;
	head = new;
	return head;
}
Node* graph[100001];
int visit[100001];
int ary[100001];
int result = 0;
void dfs(int start, int count, int k)
{
	if (ary[start] == 1)
	{
		result++;
	}
	visit[start] = 1;
	for (Node* i = graph[start]; i != NULL; i = i->link)
	{
		if (visit[i->data] == 0)
		{
			if (count == k)
			{
				return;
			}
			else
			{
				dfs(i->data, count + 1, k);
			}
		}
	}
}

int main(void)
{
	int count = 0;
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++)
	{
		int start = 0;
		int end = 0;
		scanf("%d %d", &start, &end);
		graph[start] = insert(graph[start], end);
		graph[end] = insert(graph[end], start);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ary[i]);
	}
	dfs(0, count, k);
	printf("%d", result);
}