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
	cin >> n >> m;
	string result = "";
	for (int i = 0; i < n / 2; i++) {
		result += 'A';
	}
	for (int i = 0; i < n - n / 2; i++) {
		result += 'B';
	}
	if ((n / 2) * (n - n / 2) < m) {
		cout << -1;
		return 0;
	}
	ll temp = (n / 2) * (n - n / 2);
	ll idx = n - 1;
	while (temp != m) {
		vector<ll>v;
		for (int i = 0; i < n; i++) {
			if (result[i] == 'A') {
				v.push_back(i);
			}
		}
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] != n - 1 && result[v[i] + 1] != 'A') {
				swap(result[v[i]], result[v[i] + 1]);
				break;
			}
		}
		temp--;
	}
	cout << result;
	return 0;
}