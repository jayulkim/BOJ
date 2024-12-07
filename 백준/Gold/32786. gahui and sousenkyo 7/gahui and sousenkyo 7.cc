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
	cin >> n >> m >> k;
	if (!k) {
		ll count = n + 1;
		vector<ll>v;
		for (int i = 1; i <= n; i++) {
			v.push_back(i);
		}
		for (int i = 0; i < m; i++) {
			for (auto& j : v) {
				cout << j << ' ';
			}
			cout << '\n';
			v[0] = count++;
		}
		return 0;
	}
	vector<ll>v;
	for (int i = 0; i < k; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	vector<vector<ll>>vv;
	ll count = 1;
	vector<ll>dq;
	for (int i = 1; i <= v[0]; i++) {
		dq.push_back(count++);
	}
	vv.push_back(dq);
	for (int i = 1; i < k; i++) {
		vector<ll>temp;
		for (int j = v[i - 1] + 1; j <= v[i]; j++) {
			temp.push_back(count++);
		}
		vv.push_back(temp);
	}
	vector<ll>().swap(dq);
	for (int i = v.back() + 1; i <= n; i++) {
		dq.push_back(count++);
	}
	vv.push_back(dq);
	vector<ll>a, b;
	for (auto& j : vv) {
		for (auto& u : j) {
			a.push_back(u);
		}
	}
	for (auto& j : vv) {
		reverse(j.begin(), j.end());
		for (auto& u : j) {
			b.push_back(u);
		}
	}
	for (int i = v.back(); i < n; i++) {
		b[i] = count++;
	}
	ll cnt = 0;
	while (cnt < m) {
		for (auto& j : a) {
			cout << j << ' ';
		}
		cout << '\n';
		cnt++;
		if (cnt == m) {
			break;
		}
		for (auto& j : b) {
			cout << j << ' ';
		}
		cout << '\n';
		cnt++;
		if (cnt == m) {
			break;
		}
	}
	return 0;
}