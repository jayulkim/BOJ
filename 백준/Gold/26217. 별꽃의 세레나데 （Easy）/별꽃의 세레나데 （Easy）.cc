#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<string, string, ll> tp;
typedef pair<ll, ll> pll;
ld n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cout << fixed;
	cout.precision(20);
	ld result = 0;
	for (ll i = n; i >= 1; i--) {
		result += (n / (ld)i);
	}
	cout << result;
	return 0;
}