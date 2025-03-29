#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, char> llc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	map<string, ll>Map;
	ll id = 0;
	for (int i = 0; i < n; i++) {
		string str = "";
		cin >> str;
		Map[str] = ++id;
	}
	cin >> m;
	vector<bitset<201>>v;
	for (int i = 0; i < m; i++) {
		ll a = 0;
		string str = "";
		cin >> a >> str;
		bitset<201>temp;
		for (int j = 0; j < a; j++) {
			string str = "";
			cin >> str;
			temp.set(Map[str]);
		}
		v.push_back(temp);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		ll a = 0;
		cin >> a;
		bitset<201>temp;
		ll count = 0;
		for (int j = 0; j < a; j++) {
			string str = "";
			cin >> str;
			temp.set(Map[str]);
		}
		for (auto& j : v) {
			if ((j & temp) == temp) {
				count++;
			}
		}
		cout << count << '\n';
	}
	return 0;
}