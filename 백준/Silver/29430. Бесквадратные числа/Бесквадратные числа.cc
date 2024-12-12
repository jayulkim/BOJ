#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool visited[10000001];
bool v[10000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= 10000000; i++) {
		if (!visited[i]) {
			for (int j = i * i; j <= 10000000; j += i) {
				visited[j] = true;
			}
		}
	}
	vector<ll>sosoo;
	for (int i = 2; i <= 10000000; i++) {
		if (!visited[i]) {
			sosoo.push_back(i);
		}
	}
	for (auto& i : sosoo) {
		if (i * i <= 10000000 && !v[i * i]) {
			for (int j = i * i; j <= 10000000; j += (i * i)) {
				v[j] = true;
			}
		}
	}
	cin >> n >> m >> k;
	ll count = 0;
	for (int i = m; i <= k; i++) {
		if (!v[i]) {
			count++;
		}
		if (count == n) {
			cout << i;
			return 0;
		}
	}
	return 0;
}