#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 987654321
long long int dist[20001];
typedef struct info {
	int end;
	long long int weight;
}info;
typedef struct Node {
	info data;
	struct Node* link;
}Node;
Node* graph[20001];
Node* insert(Node* head, info num) {
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->link = head;
	head = new;
	return new;
}
typedef struct Heap {
	int size;
	info heap[300001];
}Heap;
Heap* create() {
	Heap* new = (Heap*)malloc(sizeof(Heap));
	new->size = 0;
	return new;
}
void swap(info* num1, info* num2) {
	info temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void insert1(Heap* h, info num) {
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size].weight < h->heap[size / 2].weight) {
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
info delete(Heap* h) {
	info root = h->heap[1];
	int parent = 1;
	int child = 2;
	info temp = h->heap[h->size--];
	h->heap[1] = temp;
	while (child <= h->size) {
		if (child < h->size && h->heap[child].weight > h->heap[child + 1].weight) {
			child++;
		}
		if (temp.weight <= h->heap[child].weight) {
			break;
		}
		swap(&h->heap[parent], &h->heap[child]);
		parent = child;
		child *= 2;
	}
	return root;
}
void dijkstra(int start) {
	Heap* h = create();
	for (int i = 0; i <= 20000; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	info st = { start, 0 };
	insert1(h, st);
	while (h->size != 0) {
		info temp = delete(h);
		if (dist[temp.end] >= temp.weight) {
			for (Node* i = graph[temp.end]; i != NULL; i = i->link) {
				if (dist[i->data.end] > dist[temp.end] + i->data.weight) {
					dist[i->data.end] = dist[temp.end] + i->data.weight;
					info it = { i->data.end, dist[i->data.end] };
					insert1(h, it);
				}
			}
		}
	}
}
int main(void) {
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	int start = 0;
	scanf("%d", &start);
	for (int i = 0; i < m; i++) {
		int start = 0;
		info temp;
		scanf("%d %d %lld", &start, &temp.end, &temp.weight);
		graph[start] = insert(graph[start], temp);
	}
	dijkstra(start);
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			printf("%lld\n", dist[i]);
		}
		else {
			printf("INF\n");
		}
	}
	return 0;
}