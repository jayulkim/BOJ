#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<ll, ll>Map;
ll dfs(ll n, ll m, ll k) {
	if (n == 0) {
		return 1;
	}
	if (Map[n]) {
		return Map[n];
	}
	return Map[n] = dfs(n / m, m, k) + dfs(n / k, m, k);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Map[0] = 1;
	cin >> n >> m >> k;
	cout << dfs(n, m, k);
	return 0;
}