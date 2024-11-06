#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
vector<ll>tree[11];
bool visited[1051];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	ll temp = 1;
	for (int i = 0; i < n; i++) {
		temp *= 2;
	}
	vector<ll>v;
	for (int i = 0; i < temp - 1; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < v.size(); j += 2) {
			tree[i].push_back(v[j]);
			visited[j] = true;
		}
		vector<ll>ary;
		for (int j = 0; j < v.size(); j++) {
			if (!visited[j]) {
				ary.push_back(v[j]);
			}
		}
		v = ary;
	}
	for (int i = 1; i <= n; i++) {
		for (auto& j : tree[i]) {
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}