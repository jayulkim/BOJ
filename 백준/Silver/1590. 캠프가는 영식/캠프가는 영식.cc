#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct info {
	ll start;
	ll temp;
	int count;
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, t = 0;
	cin >> n >> t;
	vector<info>v(n);
	ll Min = 987654321000;
	for (int i = 0; i < n; i++) {
		cin >> v[i].start >> v[i].temp >> v[i].count;
		while (v[i].count--) {
			if (v[i].start >= t) {
				Min = min(Min, abs(v[i].start - t));
			}
			v[i].start += v[i].temp;
		}
	}
	if (Min == 987654321000) {
		cout << -1;
		return 0;
	}
	cout << Min;
	return 0;
}