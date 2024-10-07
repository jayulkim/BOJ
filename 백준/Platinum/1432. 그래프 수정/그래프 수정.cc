#include <bits/stdc++.h>
using namespace std;
vector<int>graph[51];
int degree[51];
int n = 0;
priority_queue<int>pq;
int result[51];
int temp = 0;
bool Find = false;
void toposort(int n) {
	temp = n;
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) {
			pq.push(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!pq.empty()) {
			int t = pq.top();
			pq.pop();
			result[t] = temp;
			temp--;
			for (auto& j : graph[t]) {
				if (--degree[j] == 0) {
					pq.push(j);
				}
			}
		}
		else {
			cout << -1;
			Find = true;
			return;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		result[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		string str = "";
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == '1') {
				graph[j + 1].push_back(i);
				degree[i]++;
			}
		}
	}
	toposort(n);
	if (Find) {
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << ' ';
	}
	return 0;
}