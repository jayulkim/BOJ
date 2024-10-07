#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll ary[10001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<pair<ll, ll>>v;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			ll a = v[i].first + v[j].first * v[i].second;
			ll b = v[j].first + v[i].first * v[j].second;
			if (a > b) {
				ary[i]++;
			}
			else {
				ary[j]++;
			}
		}
	}
	ll result = 0;
	vector<pair<ll, ll>>s;
	for (int i = 0; i < n; i++) {
		s.push_back({ ary[i], i + 1 });
	}
	sort(s.begin(), s.end(), greater<pair<ll, ll>>());
	for (int i = 0; i < n; i++) {
		cout << s[i].second << '\n';
	}
	return 0;
}