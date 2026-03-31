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
	cin >> n >> m;
	string str = "";
	cin >> str;
	vector<ll>graph(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> graph[i];
	}
	vector<vector<ll>>cycle(n + 1);
	vector<pll>idx(n + 1, {-1, -1});
	ll size = 0;
	function<void(ll, ll)> dfs = [&](ll a, ll b) -> void {
		cycle[size].push_back(a);
		idx[a] = { size, b };
		if (idx[graph[a]].first == -1) {
			dfs(graph[a], b + 1);
		}
		};
	for (int i = 1; i <= n; i++) {
		if (idx[i].first == -1) {
			dfs(i, 0);
			size++;
		}
	}
	sort(all(str));
	vector<char>result(n + 1);
	for (int i = 1; i <= n; i++) {
		auto [a, b] = idx[i];
		result[cycle[a][(b - m % cycle[a].size() + cycle[a].size()) % cycle[a].size()]] = str[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i];
	}
	return 0;
}