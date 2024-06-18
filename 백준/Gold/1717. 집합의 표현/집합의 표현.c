#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int parent[1000001];
void init(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}
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
int main(void) {
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	init(n);
	for (int i = 0; i < m; i++) {
		int command = 0, start = 0, end = 0;
		scanf("%d %d %d", &command, &start, &end);
		if (command == 0) {
			merge(start, end);
		}
		else {
			if (getParent(start) == getParent(end)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}