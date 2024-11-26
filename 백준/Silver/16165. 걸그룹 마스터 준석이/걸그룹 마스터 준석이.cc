#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<string, ll>Map;
map<string, ll>member;
vector<string>vv(101);
vector<string>v[101];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ll count = 0;
	for (int i = 0; i < n; i++) {
		string name = "";
		cin >> name;
		Map[name] = count;
		vv[count] = name;
		cin >> k;
		for (int j = 0; j < k; j++) {
			string str = "";
			cin >> str;
			v[count].push_back(str);
			member[str] = count;
		}
		sort(v[count].begin(), v[count].end());
		count++;
	}
	for (int i = 0; i < m; i++) {
		string name = "";
		ll a = 0;
		cin >> name >> a;
		if (a == 0) {
			for (auto& j : v[Map[name]]) {
				cout << j << '\n';
			}
		}
		else {
			cout << vv[member[name]] << '\n';
		}
	}
	return 0;
}