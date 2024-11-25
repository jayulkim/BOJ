#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>graph[51];
bool check[51][51];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
		check[start][end] = true;
		check[end][start] = true;
	}
	vector<ll>result;
	ll count = n * n - m;
	while (1) {
		bool find = false;
		ll temp = 0;
		vector<pll>v;
		for (int i = 1; i <= n; i++) {
			for (auto& k : graph[i]) {
				for (auto& u : graph[k]) {
					if (i != u && !check[i][u]) {
						check[i][u] = true;
						check[u][i] = true;
						v.push_back({ i, u });
						temp++;
						find = true;
					}
				}
			}
		}
		if (!find) {
			break;
		}
		for (auto& j : v) {
			graph[j.first].push_back(j.second);
			graph[j.second].push_back(j.first);
		}
		result.push_back(temp);
	}
	cout << result.size() << '\n';
	for (auto& i : result) {
		cout << i << '\n';
	}
	return 0;
}