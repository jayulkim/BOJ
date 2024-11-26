#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	ll sum = 0;
	for (int i = 1; i <= n - 1; i++) {
		sum += v[i];
		if (sum <= 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}