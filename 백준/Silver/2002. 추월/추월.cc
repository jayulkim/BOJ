#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
vector<string>v;
map<string, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str = "";
		cin >> str;
		v.push_back(str);
	}
	for (int i = 0; i < n; i++) {
		string str = "";
		cin >> str;
		Map[str] = i;
	}
	ll count = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (Map[v[i]] < Map[v[j]]) {
				count++;
				break;
			}
		}
	}
	cout << count;
	return 0;
}