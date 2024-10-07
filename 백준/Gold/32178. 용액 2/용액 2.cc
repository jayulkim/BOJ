#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll num = 1e18, result = 0;
	int s = 0, t = 0;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	vector<pair<ll, ll>>sum(n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i].first = sum[i - 1].first + v[i];
		sum[i].second = i;
	}
	sort(sum.begin(), sum.end());
	for (int i = 1; i <= n; i++) {
		if (sum[i].first - sum[i - 1].first < num) {
			s = sum[i - 1].second;
			t = sum[i].second;
			num = sum[i].first - sum[i - 1].first;
			if (s > t) {
				swap(s, t);
				result = -num;
			}
			else {
				result = num;
			}
		}
	}
	cout << result << '\n';
	cout << s + 1 << ' ' << t;
	return 0;
}