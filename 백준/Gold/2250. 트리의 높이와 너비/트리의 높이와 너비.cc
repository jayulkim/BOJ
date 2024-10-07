#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool parent[10001];
int level[10001];
vector<int>graph[10001];
vector<int>result[10001];
int pos = 1, depth = 1;
void inorder(int start, int lv) {
	if (graph[start].size()) {
		inorder(graph[start][0], lv + 1);
	}
	if (start != -1) {
		depth = max(depth, lv);
		level[start] = lv;
		result[level[start]].push_back(pos++);
	}
	if (graph[start].size()) {
		inorder(graph[start][1], lv + 1);
	}
	
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (b != -1) {
			parent[b] = true;
		}
		if (c != -1) {
			parent[c] = true;
		}
		graph[a].push_back(b);
		graph[a].push_back(c);
	}
	for (int i = 1; i <= n; i++) {
		if (!parent[i]) {
			inorder(i, 1);
			break;
		}
	}
	int node = n + 1, weight = 0;
	for (int i = 1; i <= depth; i++) {
		if (weight < result[i].back() - result[i][0] + 1) {
			weight = result[i].back() - result[i][0] + 1;
			node = i;
		}
	}
	cout << node << ' ' << weight;
	return 0;
}