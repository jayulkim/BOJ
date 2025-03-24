#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll a[4001];
ll b[4001];
ll c[4001];
ll d[4001];
vector<ll>aa;
vector<ll>bb;
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			aa.push_back(a[i] + b[j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bb.push_back(c[i] + d[j]);
		}
	}
	ll count = 0;
	sort(bb.begin(), bb.end());
	for (int i = 0; i < aa.size(); i++) {
		ll a = lower_bound(bb.begin(), bb.end(), -aa[i]) - bb.begin(), b = upper_bound(bb.begin(), bb.end(), -aa[i]) - bb.begin();
		count += b - a;
	}
	cout << count;
	return 0;
}