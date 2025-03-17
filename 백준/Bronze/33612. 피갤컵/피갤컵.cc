#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n == 1) { 
		cout << 2024 << ' ' << 8;
	}
	else if (n == 2) {
		cout << 2025 << ' ' << 3;
	}
	else if (n == 3) {
		cout << 2025 << ' ' << 10;
	}
	else if (n == 4) {
		cout << 2026 << ' ' << 5;
	}
	else if (n == 5) {
		cout << 2026 << ' ' << 12;
	}
	return 0;
}