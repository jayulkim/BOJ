#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>ary(71);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ary[1] = 1;
	for (int i = 2; i <= 70; i++) {
		ary[i] = ary[i - 1] + ary[i - 2];
	}
	ll num = 0;
	cin >> num;
	while (num--) {
		ll n = 0;
		cin >> n;
		vector<ll>result;
		while (n > 0) {
			ll idx = lower_bound(ary.begin(), ary.end(), n) - ary.begin();
			if (ary[idx] > n) {
				idx--;
			}
			result.push_back(ary[idx]);
			n -= ary[idx];
		}
		sort(result.begin(), result.end());
		for (auto& i : result) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}