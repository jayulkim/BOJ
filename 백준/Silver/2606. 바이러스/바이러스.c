#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int visited[101];
typedef struct Node {
	int data;
	struct Node* link;
}Node;
Node* graph[101];
Node* insert(Node* head, int num) {
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->link = head;
	head = new;
	return head;
}
void dfs(int start) {
	visited[start] = 1;
	for (Node* i = graph[start]; i != NULL; i = i->link) {
		if (visited[i->data] == 0) {
			dfs(i->data);
		}
	}
}
int main(void) {
	int n = 0, m = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		scanf("%d %d", &start, &end);
		graph[start] = insert(graph[start], end);
		graph[end] = insert(graph[end], start);
	}
	dfs(1);
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1) {
			count++;
		}
	}
	printf("%d", count - 1);
	return 0;
}