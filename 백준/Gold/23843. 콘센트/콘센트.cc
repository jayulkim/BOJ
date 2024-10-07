#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(n);
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int idx = 0;
	int time = 0;
	while (pq.size() < m && idx < n) {
		pq.push(v[idx]);
		idx++;
	}
	while (idx < n) {
		int temp = pq.top();
		pq.pop();
		pq.push(v[idx] + temp);
		idx++;
	}
	while (!pq.empty()) {
		time = pq.top();
		pq.pop();
	}
	cout << time;
	return 0;
}