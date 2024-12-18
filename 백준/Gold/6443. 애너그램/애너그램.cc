#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		string str = "";
		cin >> str;
		map<string, ll>Map;
		sort(str.begin(), str.end());
		do {
			if (!Map[str]) {
				Map[str]++;
			}
		} while (next_permutation(str.begin(), str.end()));
		for (auto& i : Map) {
			cout << i.first << '\n';
		}
	}
	return 0;
}