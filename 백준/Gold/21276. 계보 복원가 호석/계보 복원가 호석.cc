#include <bits/stdc++.h>
using namespace std;
int degree[1001];
map<string, int>Map;
vector<int>graph[1001];
int n = 0, m = 0;
vector<string>v;
vector<int>result[1001];
void toposort() {
	priority_queue<int, vector<int>, greater<int>>pq;
	vector<int>parent;
	for (int i = 0; i < n; i++) {
		if (!degree[i]) {
			pq.push(i);
			parent.push_back(i);
		}
	}
	cout << pq.size() << '\n';
	sort(parent.begin(), parent.end());
	for (auto& i : parent) {
		cout << v[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		if (!pq.empty()) {
			int temp = pq.top();
			pq.pop();
			for (auto& j : graph[temp]) {
				if (--degree[j] == 0) {
					pq.push(j);
					result[temp].push_back(j);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		sort(result[i].begin(), result[i].end());
		cout << v[i] << ' ';
		cout << result[i].size() << ' ';
		for (auto& j : result[i]) {
			cout << v[j] << ' ';
		}
		cout << '\n';
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str = "";
		cin >> str;
		v.push_back(str);
	}
	cin >> m;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		Map.insert({ v[i], i });
	}
	for (int i = 0; i < m; i++) {
		string start = "", end = "";
		cin >> end >> start;
		degree[Map[end]]++;
		graph[Map[start]].push_back(Map[end]);
	}
	toposort();
	return 0;
}