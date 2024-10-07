#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll dist[100001];
struct info {
	ll end;
	ll weight;
	ll time;
	bool operator()(const info& a, const info& b) {
		return a.weight > b.weight;
	}
};
vector<info>graph[100001];
priority_queue<info, vector<info>, info>pq;
vector<ll>result;
void dijkstra() {
	ll start = 0, end = 1000000011, mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		for (int i = 1; i <= n; i++) {
			dist[i] = LLONG_MAX;
		}
		dist[1] = 0;
		pq.push({ 1, 0, LLONG_MAX });
		while (!pq.empty()) {
			info temp = pq.top();
			pq.pop();
			if (dist[temp.end] >= temp.weight) {
				for (auto& i : graph[temp.end]) {
					if (dist[temp.end] + i.weight + mid <= i.time && dist[i.end] > dist[temp.end] + i.weight) {
						dist[i.end] = dist[temp.end] + i.weight;
						pq.push({ i.end, dist[i.end], i.time });
					}
				}
			}
		}
		if (dist[n] == LLONG_MAX) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			result.push_back(mid);
		}
	}
	if (!result.size()) {
		cout << -1;
	}
	else {
		sort(result.begin(), result.end());
		cout << result.back();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0, weight = 0, time = 0;
		cin >> start >> end >> weight >> time;
		graph[start].push_back({ end, weight, time });
		graph[end].push_back({ start, weight, time });
	}
	dijkstra();
	return 0;
}