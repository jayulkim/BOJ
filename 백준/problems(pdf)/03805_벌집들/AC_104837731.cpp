#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	ll count = 1;
	while (num--) {
		cin >> n >> m;
		vector<vector<ll>>graph(n + 1);
		for (int i = 0; i < m; i++) {
			ll a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		ll Min = LLONG_MAX;
		for (int i = 0; i < n; i++) {
			vector<ll>vi(n + 1, 0);
			queue<lll>q;
			q.push({ i, 1, -1 });
			while (!q.empty()) {
				auto [a, b, c] = q.front();
				q.pop();
				vi[a] = b;
				for (auto& j : graph[a]) {
					if (vi[j]) {
						if (j != c) {
							Min = min(Min, vi[j] + b - 1);
						}
					}
					else {
						vi[j] = b + 1;
						q.push({ j, b + 1, a });
					}
				}
			}
		}
		if (Min == LLONG_MAX) {
			cout << "Case " << count++ << ": " << "impossible" << '\n';
		}
		else {
			cout << "Case " << count++ << ": " << Min << '\n';
		}
	}
	return 0;
}