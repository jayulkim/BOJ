#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<psl>v;
string result = "";
ll Count = 0;
string solve = "";
bool check(string str) {
	for (auto& i : v) {
		ll count = 0;
		for (int j = 0; j < n; j++) {
			if (i.first[j] == str[j] && str[j] == '1') {
				count++;
			}
		}
		if (count != i.second) {
			return false;
		}
	}
	return true;
}
void dfs() {
	if (result.length() == n) {
		if (check(result)) {
			Count++;
			solve = result;
		}
		return;
	}
	for (int i = 0; i <= 1; i++) {
		result += to_string(i);
		dfs();
		result.pop_back();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string str = "";
		ll num = 0;
		cin >> str >> num;
		v.push_back({ str, num });
	}
	dfs();
	if (Count == 1) {
		cout << solve;
	}
	else if (!Count) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << "NOT UNIQUE";
	}
	return 0;
}