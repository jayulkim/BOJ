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
typedef struct queue {
	int size;
	int front;
	int back;
	int* q;
}queue;
queue* create(int size) {
	queue* new = (queue*)malloc(sizeof(queue));
	new->size = size + 1;
	new->front = 0;
	new->back = 0;
	new->q = (int*)malloc(sizeof(int) * new->size);
	return new;
}
void push(queue* q, int num) {
	q->back = (q->back + 1 + q->size) % q->size;
	q->q[q->back] = num;
}
int pop(queue* q) {
	q->front = (q->front + 1 + q->size) % q->size;
	return q->q[q->front];
}
void bfs(int start, int n) {
	visited[start];
	queue* q = create(n);
	push(q, start);
	while (q->front != q->back) {
		int temp = pop(q);
		visited[temp] = 1;
		for (Node* i = graph[temp]; i != NULL; i = i->link) {
			if (visited[i->data] == 0) {
				push(q, i->data);
				visited[i->data] = 1;
			}
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
	bfs(1, n);
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1) {
			count++;
		}
	}
	printf("%d", count - 1);
	return 0;
}