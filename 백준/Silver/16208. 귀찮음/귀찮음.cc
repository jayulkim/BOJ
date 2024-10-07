#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll result = 0;
vector<ll>v;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		sum += num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = n - 1; i >= 0; i--) {
		result += (v[i] * (sum -= v[i]));
	}
	cout << result;
	return 0;
}