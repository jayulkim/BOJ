#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
ll n = 0, m = 0, k = 0;
vector<ll>graph[1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	vector<plc>v(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> v[i].first >> v[i].second;
	}
	ll result = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[j].second == 'R') {
				if (v[j].first == n) {
					v[j].second = 'L';
					v[j].first--;
				}
				else {
					v[j].first++;
				}
			}
			else {
				if (!v[j].first) {
					v[j].second = 'R';
					v[j].first++;
				}
				else {
					v[j].first--;
				}
			}
			graph[v[j].first].push_back(j);
		}
		for (int j = 0; j <= n; j++) {
			if (graph[j].size() == 2) {
				result++;
				if (v[graph[j][0]].second == 'R') {
					v[graph[j][0]].second = 'L';
				}
				else {
					v[graph[j][0]].second = 'R';
				}
				if (v[graph[j][1]].second == 'R') {
					v[graph[j][1]].second = 'L';
				}
				else {
					v[graph[j][1]].second = 'R';
				}
			}
			vector<ll>().swap(graph[j]);
		}
	}
	cout << result;
	return 0;
}