#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	vector<lll>v(n + 1);
	vector<map<ll, ll>>color(n + 1);
	ll count = n - 1;
	for (int i = 1; i <= n - 1; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		v[i] = { a, b, c };
		color[a][c]++;
		if (color[a][c] >= 2) {
			count--;
		}
		color[b][c]++;
		if (color[b][c] >= 2) {
			count--;
		}
	}
	for (int i = 0; i < k; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		auto [c, d, e] = v[a];
		if (e == b) {
			cout << count << '\n';
			continue;
		}
		count += (color[c][e] >= 2);
		count += (color[d][e] >= 2);
		count -= (color[c][b] > 0);
		count -= (color[d][b] > 0);
		color[c][e]--;
		color[d][e]--;
		color[c][b]++;
		color[d][b]++;
		v[a] = { c, d, b };
		cout << count << '\n';
	}
	return 0;
}