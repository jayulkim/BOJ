#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<pll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].second;
	}
	vector<ll>result;
	for (int i = 0; i < n; i++) {
		if (v[i].first >= v[i].second) {
			result.push_back(v[i].second);
		}
		else {
			if (v[i].first == 1) {
				result.push_back(1);
			}
			else {
				ll start = 0, end = 1e9, mid = 0;
				ll Min = LLONG_MAX;
				while (start <= end) {
					mid = (start + end) / 2;
					ll temp = mid;
					ll a = mid, b = 0;
					while (1) {
						temp += (a / v[i].first);
						b = a % v[i].first;
						if ((b + a / v[i].first) >= v[i].first) {
							a = (b + a / v[i].first);
						}
						else {
							break;
						}
					}
					if (temp >= v[i].second) {
						end = mid - 1;
						Min = min(Min, mid);
					}
					else {
						start = mid + 1;
					}
				}
				result.push_back(Min);
			}
		}
	}
	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0;
}