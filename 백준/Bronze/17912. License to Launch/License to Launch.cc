#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
	ll Min = LLONG_MAX;
	ll temp = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a = 0;
		cin >> a;
		if (a < Min) {
			Min = a;
			temp = i;
		}
	}
	cout << temp;
	return 0;
    return 0;
 }