#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
bool visited[10001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<char>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] == 'R') {
			for (int j = i - k; j <= i + k; j++) {
				if (j >= 1 && j <= n) {
					visited[j] = true;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			m--;
		}
	}
	if (m >= 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}