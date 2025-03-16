#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n % 10) {
		cout << -1;
		return 0;
	}
	ll a = 0, b = 0, c = 0;
	while (n - 300 >= 0) {
		n -= 300;
		a++;
	}
	while (n - 60 >= 0) {
		n -= 60;
		b++;
	}
	while (n - 10 >= 0) {
		n -= 10;
		c++;
	}
	cout << a << ' ' << b << ' ' << c;
	return 0;
}