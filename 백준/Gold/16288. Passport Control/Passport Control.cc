#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll idx[101];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		idx[v[i]] = i;
	}
	deque<ll>dq[101];
	for (int i = 1; i <= n; i++) {
		bool visited[101];
		memset(visited, false, sizeof(visited));
		for (int j = idx[i] + 1; j < n; j++) {
			if (idx[i] + 1 < n) {
				visited[v[j]] = true;
			}
		}
		bool find = false;
		for (int j = 0; j < m; j++) {
			if (dq[j].empty() || !visited[dq[j].back()]) {
				dq[j].push_back(i);
				find = true;
				break;
			}
		}
		if (!find) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}