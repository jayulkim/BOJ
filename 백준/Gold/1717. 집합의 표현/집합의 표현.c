#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int parent[1000001];
int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}
int merge(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}
int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) {
		return 1;
	}
	return 0;
}
int main(void) {
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int command = 0, start = 0, end = 0;
		scanf("%d %d %d", &command, &start, &end);
		if (command == 0) {
			merge(start, end);
		}
		else if (command == 1) {
			if (findParent(start, end) == 1) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}