#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
bool visited[5000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= 5000000; i++) {
		if (!visited[i]) {
			for (int j = i * i; j <= 5000000; j += i) {
				visited[j] = true;
			}
		}
	}
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			v.push_back(i);
		}
	}
	for (int i = 0; i < m; i++) {
		ll start = 0, end = 0;
		cin >> start >> end;
		auto it = upper_bound(v.begin(), v.end(), end);
		it--;
		cout << (it - v.begin()) - (lower_bound(v.begin(), v.end(), start) - v.begin()) + 1 << '\n';
	}
	return 0;
}