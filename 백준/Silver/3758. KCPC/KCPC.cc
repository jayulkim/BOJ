#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;
lll dp[101][101];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		ll a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		for (int i = 0; i < d; i++) {
			ll aa = 0, bb = 0, cc = 0;
			cin >> aa >> bb >> cc;
			dp[aa][bb] = { max(get<0>(dp[aa][bb]), cc), get<1>(dp[aa][bb]) + 1, i };
		}
		vector<lll>v;
		ll aaa = 0, bbb = 0, ccc = 0;
		for (int i = 1; i <= a; i++) {
			ll sum = 0;
			ll count = 0;
			ll last = 0;
			for (int j = 1; j <= b; j++) {
				sum += get<0>(dp[i][j]);
				count += get<1>(dp[i][j]);
				last = max(last, get<2>(dp[i][j]));
			}
			if (i == c) {
				aaa = sum;
				bbb = count;
				ccc = last;
			}
			else {
				v.push_back({ sum, count, last });
			}	
		}
		ll count = 0;
		for (auto& [aa, bb, cc] : v) {
			if (aa > aaa) {
				count++;
			}
			else if (aa == aaa) {
				if (bb < bbb) {
					count++;
				}
				else if (bb == bbb) {
					if (cc < ccc) {
						count++;
					}
				}
			}
		}
		cout << count + 1 << '\n';
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}