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
class Toposort {
private:
	using ll = long long;
	ll n;
	vector<vector<ll>>dag;
public:
	Toposort(ll n, const vector<vector<ll>>& dag) {
		this->n = n;
		this->dag = dag;
	}
	pair<bool, vector<ll>> toposort() {
		vector<ll>degree(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			for (auto& j : dag[i]) {
				degree[j]++;
			}
		}
		vector<ll>result;
		queue<ll>q;
		for (int i = 1; i <= n; i++) {
			if (!degree[i]) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			ll temp = q.front();
			q.pop();
			result.push_back(temp);
			for (auto& i : dag[temp]) {
				if (--degree[i] == 0) {
					q.push(i);
				}
			}
		}
		return { result.size() == n, result};
	}
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<vector<ll>>graph(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> k;
		ll prev = 0;
		for (int j = 0; j < k; j++) {
			ll a = 0;
			cin >> a;
			if (!j) {
				prev = a;
			}
			else {
				graph[prev].push_back(a);
				prev = a;
			}
		}
	}
	Toposort t(n, graph);
	pair<bool, vector<ll>>result = t.toposort();
	if (!result.first) {
		cout << 0;
	}
	else {
		for (auto& i : result.second) {
			cout << i << '\n';
		}
	}
	return 0;
}