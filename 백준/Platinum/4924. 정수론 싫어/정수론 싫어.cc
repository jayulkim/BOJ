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
	vector<ll>f(1000001, 0);
	f[1] = 0;
	vector<bool>visited(1000001, false);
	for (int i = 2; i <= 1000000; i++) {
		if (!f[i]) {
			f[i] = -1;
			for (int j = i * 2; j <= 1000000; j += i) {
				ll temp = j;
				while (temp % i == 0) {
					f[j]++;
					temp /= i;
				}
			}
		}
	}
	vector<ll>fsum(1000001, 0);
	for (int i = 1; i <= 1000000; i++) {
		fsum[i] = fsum[i - 1] + f[i];
	}
	vector<ll>vv(1000001, 0);
	ll count = 1;
	while (1) {
		cin >> n >> m;
		if (n == -1 && m == -1) {
			break;
		}
		ll Max = -LLONG_MAX;
		vv[n - 1] = n;
		for (int i = n; i <= m; i++) {
			vv[i] = n;
			if (fsum[i] - fsum[vv[i - 1] - 1] - (i - vv[i - 1] + 1) < f[i] - 1) {
				Max = max(Max, f[i] - 1);
				vv[i] = i;
			}
			else {
				Max = max(Max, fsum[i] - fsum[vv[i - 1] - 1] - (i - vv[i - 1] + 1));
				vv[i] = vv[i - 1];
			}
		}
		cout << count++ << '.' << ' ' << Max << '\n';
	}
	return 0;
}