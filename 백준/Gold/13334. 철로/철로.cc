#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		if (v[i].second < v[i].first) {
			swap(v[i].second, v[i].first);
		}
	}
	sort(v.begin(), v.end(), compare);
	int k = 0;
	cin >> k;
	vector<pair<int, int>>ary;
	for (int i = 0; i < n; i++) {
		if (v[i].second - v[i].first <= k) {
			ary.push_back({ v[i].first, v[i].second });
		}
	}
	int start = 0, end = 0, idx = 0, Max = 0;
	priority_queue<int, vector<int>, greater<int>>pq;
	while (idx < ary.size()) {
		end = ary[idx].second;
		start = end - k;
		while (!pq.empty() && pq.top() < start) {
			pq.pop();
		}
		if (idx < ary.size() && ary[idx].first >= start) {
			pq.push(ary[idx].first);
			idx++;
		}
		Max = max(Max, (int)pq.size());
	}
	cout << Max;
	return 0;
}