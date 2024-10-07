#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll result = 0;
	ll count = 0;
	for (int i = 0; i < n; i++) {
		result += v[i] * count;
		if (count < k) {
			count++;
		}
	}
	cout << result;
	return 0;
}