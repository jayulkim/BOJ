#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
vector<ll>parent(200001);
vector<ll>vv(200001, 1);
ll getparent(ll x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getparent(parent[x]);
}
void merge(ll a, ll b) {
	a = getparent(a);
	b = getparent(b);
	if (a > b) {
		parent[a] = b;
		vv[b] += vv[a];
	}
	else {
		parent[b] = a;
		vv[a] += vv[b];
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n;
		map<string, ll>Map;
		ll count = 1;
		vector<pair<string, string>>v;
		for (int i = 0; i < n; i++) {
			string a = "", b = "";
			cin >> a >> b;
			v.push_back({ a, b });
			if (!Map[a]) {
				Map[a] = count++;
			}
			if (!Map[b]) {
				Map[b] = count++;
			}
		}
		for (int i = 1; i < count; i++) {
			parent[i] = i;
			vv[i] = 1;
		}
		for (int i = 0; i < n; i++) {
			if (getparent(Map[v[i].first]) != getparent(Map[v[i].second])) {
				merge(Map[v[i].first], Map[v[i].second]);
			}
			cout << max(vv[getparent(Map[v[i].first])], vv[getparent(Map[v[i].second])]) << '\n';
		}
	}
    return 0;
}