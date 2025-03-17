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
	cin >> m >> k;
	if (n == 3) {
        if (m == 2 && k == 2) {
            cout << 1;
        }
		else {
            cout << n * n / 2;
        }
	}
	else {
		if (n % 2 && m % 2 == k % 2) {
			cout << n * n / 2 + 1;
		}
		else {
			cout << n * n / 2;
		}
	}
	return 0;
}