#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
vector<ll>v;
vector<ll>graph;
ll Max = 0;
bool visited[9];
void dfs() {
	if (graph.size() == v.size()) {
		ll temp = 0;
		for (int i = 0; i < n - 1; i++) {
			temp += llabs(graph[i] - graph[i + 1]);
		}
		Max = max(Max, temp);
	}
	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			graph.push_back(v[i]);
			visited[i] = true;
			dfs();
			visited[i] = false;
			graph.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	dfs();
	cout << Max;
	return 0;
}