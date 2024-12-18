#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, char> plc;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	ll start = 0, end = 9999, mid = 0;
	vector<ll>vv;
	while (start <= end) {
		ll Max = 0, Min = 987654321;
		ll count = 1;
		mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			Max = max(Max, v[i]);
			Min = min(Min, v[i]);
			if (Max - Min > mid) {
				count++;
				Max = 0;
				Min = 987654321;
				i--;
			}
		}
		if (count <= m) {
			end = mid - 1;
			vv.push_back(mid);
		}
		else {
			start = mid + 1;
		}
	}
	sort(vv.begin(), vv.end());
	cout << vv[0];
	return 0;
}