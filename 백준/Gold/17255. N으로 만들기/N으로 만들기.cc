#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	cin >> str;
	map<vector<string>, ll>Map;
	string result = "";
	ll count = 0;
	vector<string>v;
	function<void(ll, ll)> dfs = [&](ll start, ll end) -> void {
		if (result.length() == str.length()) {
			if (!Map[v]) {
				Map[v]++;
				count++;
			}
			return;
		}
		if (start - 1 >= 0) {
			v.push_back(str[start - 1] + result);
			result = str[start - 1] + result;
			dfs(start - 1, end);
			v.pop_back();
			string temp = "";
			for (int i = 1; i < result.size(); i++) {
				temp += result[i];
			}
			result = temp;
		}
		if (end + 1 < str.length()) {
			v.push_back(result += str[end + 1]);
			dfs(start, end + 1);
			v.pop_back();
			result.pop_back();
		}
		};
	for (int i = 0; i < str.length(); i++) {
		result += str[i];
		v.push_back(to_string(str[i]));
		dfs(i, i);
		v.pop_back();
		result = "";
	}
	cout << count;
	return 0;
}