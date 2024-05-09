#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int visit[499501] = { 0, };
typedef struct Node
{
	int data;
	struct Node* link;
}Node;
Node* graph[499501];
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
void dfs(int start)
{
	visit[start] = 1;
	for (Node* i = graph[start]; i != NULL; i = i->link)
	{
		if (visit[i->data] == 0)
		{
			visit[i->data] = 1;
			dfs(i->data);
		}
	}
}
int main(void)
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	if (m == 0)
	{
		printf("%d", n);
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		int start = 0, end = 0;
		scanf("%d %d", &start, &end);
		insertgraph(start, end);
	}
	int result = 0;
	while (1)
	{	
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 0)
			{
				result++;
				dfs(i);
				count++;
				break;
			}
		}
		if (count == 0)
		{
			break;
		}		
	}
	printf("%d", result);
}