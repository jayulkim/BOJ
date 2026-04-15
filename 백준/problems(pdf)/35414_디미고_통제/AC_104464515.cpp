#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
typedef pair<ll, vector<ll>> plv;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<vector<ll>>graph(n + 1);
	vector<ll>vi(n + 1, 0);
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<ll>result;
	vector<ll>v;
	function<void(ll)> dfs = [&](ll a) -> void {
		vi[a] = 1;
		v.push_back(a);
		for (auto& i : graph[a]) {
			if (!vi[i]) {
				dfs(i);
			}
		}
		};
	for (int i = 1; i <= n; i++) {
		if (!vi[i]) {
			dfs(i);
			for (int j = v.size() - 1; j >= 1; j--) {
				result.push_back(v[j]);
			}
			vector<ll>().swap(v);
		}
	}
	cout << result.size() << '\n';
	for (auto& i : result) {
		cout << i << '\n';
	}
	return 0;
}