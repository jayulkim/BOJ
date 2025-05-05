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
	cin >> n;
	string str = "";
	cin >> str;
	vector<ll>v(n + 1, 0);
	vector<ll>dp(n + 1, 0);
	ll result = 0;
	for (int i = 3; i < n; i++) {
		if (str[i - 3] == 'S' && str[i - 2] == 'S' && str[i - 1] == 'H' && str[i] == 'S') {
			v[i]++;
		}
		if (str[i - 3] == 'G' && str[i - 2] == 'S' && str[i - 1] == 'H' && str[i] == 'S') {
			v[i]--;
		}
	}
	for (int i = 3; i < n; i++) {
		dp[i] = dp[i - 1] + v[i];
	}
	ll Min = 0;
	for (int i = 3; i < n; i++) {
		result = max(result, dp[i] - Min);
		Min = min(Min, dp[i]);
	}
	cout << result;
	return 0;
}