#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<ll>v;
vector<ll>maxdp(3001, -1);
vector<ll>mindp(3001, -1);
ll n = 0, m = 0;
ll updfs(ll idx) {
	if (maxdp[idx] != -1) {
		return maxdp[idx];
	}
	ll weight = 1;
	for (int i = idx + 1; i < n; i++) {
		if (v[idx] < v[i]) {
			weight = max(weight, updfs(i) + 1);
		}
	}
	return maxdp[idx] = weight;
}
ll downdfs(ll idx) {
	if (mindp[idx] != -1) {
		return mindp[idx];
	}
	ll weight = 1;
	for (int i = idx - 1; i >= 0; i--) {
		if (v[idx] > v[i]) {
			weight = max(weight, downdfs(i) + 1);
		}
	}
	return mindp[idx] = weight;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		cout << updfs(num - 1) + downdfs(num - 1) - 1 << '\n';
	}
	return 0;
}