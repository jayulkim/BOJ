#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
vector<pair<ll, ll>>graph[1001];
priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
priority_queue <ll>maxpq[1001];
void dijkstra(ll start) {
	pq.push({ 0, start });
	maxpq[1].push(0);
	while (!pq.empty()) {
		pair<ll, ll>temp = pq.top();
		pq.pop();
		for (auto& i : graph[temp.second]) {
			if (maxpq[i.second].size() < k) {
				pq.push({ temp.first + i.first, i.second });
				maxpq[i.second].push(temp.first + i.first);
			}
			else if (maxpq[i.second].size() == k && maxpq[i.second].top() > temp.first + i.first) {
				maxpq[i.second].pop();
				pq.push({ temp.first + i.first, i.second });
				maxpq[i.second].push(temp.first + i.first);
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back({ weight, end });
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++) {
		if (maxpq[i].size() < k) {
			cout << -1 << '\n';
		}
		else {
			cout << maxpq[i].top() << '\n';
		}
	}
	return 0;
}