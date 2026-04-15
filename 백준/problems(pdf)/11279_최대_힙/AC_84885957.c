#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Heap {
	int size;
	int heap[100001];
}Heap;
Heap* create() {
	return (Heap*)malloc(sizeof(Heap));
}
void init(Heap* h) {
	h->size = 0;
}
void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void insert(Heap* h, int num) {
	int size = ++(h->size);
	h->heap[size] = num;
	while (size != 1 && h->heap[size] > h->heap[size / 2]) {
		swap(&h->heap[size], &h->heap[size / 2]);
		size /= 2;
	}
}
int delete(Heap* h) {
	int root = h->heap[1];
	int parent = 1;
	int child = 2;
	int temp = h->heap[h->size--];
	h->heap[1] = temp;
	while (child <= h->size) {
		if (child < h->size && h->heap[child] < h->heap[child + 1]) {
			child++;
		}
		if (temp >= h->heap[child]) {
			break;
		}
		swap(&h->heap[parent], &h->heap[child]);
		parent = child;
		child *= 2;
	}
	return root;
}
int main(void) {
	int num = 0;
	scanf("%d", &num);
	Heap* h = create();
	init(h);
	for (int i = 0; i < num; i++) {
		int n = 0;
		scanf("%d", &n);
		if (n == 0) {
			if (h->size == 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", delete(h));
			}
		}
		else {
			insert(h, n);
		}
	}
	return 0;
}