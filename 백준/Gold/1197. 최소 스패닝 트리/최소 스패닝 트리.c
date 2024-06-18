#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int parent[10001];
int getParent(int start) {
	if (parent[start] == start) {
		return start;
	}
	return parent[start] = getParent(parent[start]);
}
void merge(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}
typedef struct info {
	int start;
	int end;
	int weight;
}info;
typedef struct Heap {
	int size;
	info heap[100001];
}Heap;
Heap* create() {
	return (Heap*)malloc(sizeof(Heap));
}
void init(Heap* h) {
	h->size = 0;
}
void swap(info* num1, info* num2) {
	info temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void insert(Heap* h, info num) {
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
int result = 0;
void kruskal(Heap* h, int n) {
	int count = 0, a = 0, b = 0;
	while (count < n - 1 && h->size != 0) {
		info temp = delete(h);
		a = getParent(temp.start);
		b = getParent(temp.end);
		if (a != b) {
			count++;
			result += temp.weight;
			merge(a, b);
		}
	}
}
int main(void) {
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	Heap* h = create();
	init(h);
	for (int i = 0; i < m; i++) {
		info temp;
		scanf("%d %d %d", &temp.start, &temp.end, &temp.weight);
		insert(h, temp);
	}
	kruskal(h, n);
	printf("%d", result);
	return 0;
}