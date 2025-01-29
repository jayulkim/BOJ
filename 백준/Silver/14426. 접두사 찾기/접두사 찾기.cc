#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
unordered_map<string, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str = "";
		cin >> str;
		string temp = "";
		for (auto& j : str) {
			temp += j;
			Map[temp]++;
		}
	}
	ll count = 0;
	for (int i = 0; i < m; i++) {
		string str = "";
		cin >> str;
		if (Map[str]) {
			count++;
		}
	}
	cout << count;
	return 0;
}