#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool visited[50000001];
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	visited[1] = true;
	for (int i = 2; i * i <= 50000000; i++) {
		if (!visited[i]) {
			for (int j = i * i; j <= 50000000; j += i) {
				visited[j] = true;
			}
		}
	}
	cin >> n >> m >> k;
	vector<ll>v;
	for (int i = n; i <= m; i++) {
		if (!visited[i]) {
			v.push_back(i);
		}
	}
	if (!v.size()) {
		cout << 0;
		return 0;
	}
	Map[0]++;
	for (int i = 0; i < v.size(); i++) {
		map<ll, ll>temp;
		for (auto& j : Map) {
			if (v[i] + j.first <= k) {
				temp[v[i] + j.first] += j.second;
			}
		}
		for (auto& j : temp) {
			Map[j.first] += j.second;
		}
	}
	cout << Map[k];
	return 0;
}