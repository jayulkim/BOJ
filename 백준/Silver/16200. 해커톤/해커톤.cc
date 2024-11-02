#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>v;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	deque<ll>dq;
	for (auto& i : v) {
		dq.push_back(i);
	}
	ll result = 0;
	while (!dq.empty()) {
		ll temp = dq.front();
		dq.pop_front();
		for (int i = 0; i < temp - 1; i++) {
			if (!dq.empty()) {
				dq.pop_front();
			}
		}
		result++;
	}
	cout << result;
	return 0;
}