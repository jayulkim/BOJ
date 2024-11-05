#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll dp[2][200001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>a;
	vector<ll>b;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		b.push_back(num);
	}
	dp[0][0] = a[0];
	dp[1][0] = b[0];
	for (int i = 1; i < n; i++) {	
		dp[0][i] = min(dp[0][i - 1] + a[i], dp[1][i - 1] + m + a[i]);
		dp[1][i] = min(dp[1][i - 1] + b[i], dp[0][i - 1] + m + b[i]);
	}
	cout << min(dp[0][n - 1], dp[1][n - 1]);
	return 0;
}