#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<vector<ll>>dp(101, vector<ll>(200001, 0));
vector<ll>v(101);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	ll num = 0;
	cin >> num;
	ll idx = 0;
	ll sum = 0;
	for (int i = 0; i < num; i++) {
		ll a = 0, b = 0;
		cin >> a >> b;
		for (int j = 1; j <= a; j++) {
			v[++idx] = b;
			sum += b;
		}
	}
	if (sum < n) {
		cout << 0;
		return 0;
	}
	sort(v.begin() + 1, v.begin() + idx + 1);
	for (int i = 1; i <= idx; i++) {
		dp[i - 1][0] = 1;
		for (int j = 1; j <= 200000; j++) {
			if (j - v[i] >= 0 && dp[i - 1][j - v[i]]) {
				dp[i][j] = 1;
			}
			if (dp[i - 1][j]) {
				dp[i][j] = 1;
			}
		}
	}
	ll Max = 0;
	ll result = 0;
	for (int i = 1; i <= 200000; i++) {
		bool find = false;
		for (int j = 1; j <= idx; j++) {
			if (dp[j][i]) {
				find = true;
				break;
			}
		}
		if (find) {
			if (Max < min(k, m * (i / n))) {
				Max = min(k, m * (i / n));
				result = i;
			}
		}
	}
	cout << result;
	return 0;
}