#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<ll>result;
	result.push_back(1);
	for (int i = 1; i <= 1000000; i++) {
		if ((n + 1) % i == 0 && i != n + 1 && i != 1) {
			result.push_back(i);
			result.push_back((n + 1) / i);
		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0;
}