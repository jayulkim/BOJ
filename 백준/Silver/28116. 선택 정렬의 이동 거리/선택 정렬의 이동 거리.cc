#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll visited[500001];
ll dist[500001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		visited[v[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		dist[i] += llabs(visited[v[i - 1]] - visited[i]);
		dist[v[i - 1]] += llabs(visited[v[i - 1]] - visited[i]);
		visited[v[i - 1]] = visited[i];
		swap(v[i - 1], v[visited[i]]);
	}
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
	return 0;
}