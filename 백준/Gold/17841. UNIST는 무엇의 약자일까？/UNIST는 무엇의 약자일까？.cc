#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
#define mod 1000000007
vector<ll>u(100001, 0);
vector<ll>usum(100001, 0);
vector<ll>un(100001, 0);
vector<ll>unsum(100001, 0);
vector<ll>uni(100001, 0);
vector<ll>unisum(100001, 0);
vector<ll>unis(100001, 0);
vector<ll>unissum(100001, 0);
vector<ll>unist(100001, 0);
vector<ll>unistsum(100001, 0);
vector<string>v(100001, "0000000000000000000000000");
ll addmod(ll x, ll y) {
	if (x >= (mod - y)) {
		return x - (mod - y);
	}
	return x + y;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i][0] == 'U') {
			u[i]++;
		}
	}
	usum[0] = u[0];
	for (int i = 1; i < n; i++) {
		usum[i] = addmod(usum[i - 1], u[i]);
	}
	for (int i = 0; i < n; i++) {
		if (v[i].length() >= 2 && v[i][0] == 'U' && v[i][1] == 'N') {
			un[i] = addmod(un[i], 1);
		}
	}
	for (int i = 1; i < n; i++) {
		if (v[i].length() >= 1 && v[i][0] == 'N') {
			un[i] = addmod(un[i], usum[i - 1]);
		}
	}
	unsum[0] = un[0];
	for (int i = 1; i < n; i++) {
		unsum[i] = addmod(unsum[i - 1], un[i]);
	}
	for (int i = 0; i < n; i++) {
		if (v[i].length() >= 3 && v[i][0] == 'U' && v[i][1] == 'N' && v[i][2] == 'I') {
			uni[i] = addmod(uni[i], 1);
		}
	}
	for (int i = 1; i < n; i++) {
		if (v[i].length() >= 1 && v[i][0] == 'I') {
			uni[i] = addmod(uni[i], unsum[i - 1]);
		}
		else if (v[i].length() >= 2 && v[i][0] == 'N' && v[i][1] == 'I') {
			uni[i] = addmod(uni[i], usum[i - 1]);
		}
	}
	unisum[0] = uni[0];
	for (int i = 1; i < n; i++) {
		unisum[i] = addmod(unisum[i - 1], uni[i]);
	}
	for (int i = 0; i < n; i++) {
		if (v[i].length() >= 4 && v[i][0] == 'U' && v[i][1] == 'N' && v[i][2] == 'I' && v[i][3] == 'S') {
			unis[i] = addmod(unis[i], 1);
		}
	}
	for (int i = 1; i < n; i++) {
		if (v[i].length() >= 1 && v[i][0] == 'S') {
			unis[i] = addmod(unis[i], unisum[i - 1]);
		}
		else if (v[i].length() >= 3 && v[i][0] == 'N' && v[i][1] == 'I' && v[i][2] == 'S') {
			unis[i] = addmod(unis[i], usum[i - 1]);
		}
		else if (v[i].length() >= 2 && v[i][0] == 'I' && v[i][1] == 'S') {
			unis[i] = addmod(unis[i], unsum[i - 1]);
		}
	}
	unissum[0] = unis[0];
	for (int i = 1; i < n; i++) {
		unissum[i] = addmod(unissum[i - 1], unis[i]);
	}
	for (int i = 0; i < n; i++) {
		if (v[i].length() >= 5 && v[i][0] == 'U' && v[i][1] == 'N' && v[i][2] == 'I' && v[i][3] == 'S' && v[i][4] == 'T') {
			unist[i] = addmod(unist[i], 1);
		}
	}
	for (int i = 1; i < n; i++) {
		if (v[i].length() >= 1 && v[i][0] == 'T') {
			unist[i] = addmod(unist[i], unissum[i - 1]);
		}
		else if (v[i].length() >= 4 && v[i][0] == 'N' && v[i][1] == 'I' && v[i][2] == 'S' && v[i][3] == 'T') {
			unist[i] = addmod(unist[i], usum[i - 1]);
		}
		else if (v[i].length() >= 3 && v[i][0] == 'I' && v[i][1] == 'S' && v[i][2] == 'T') {
			unist[i] = addmod(unist[i], unsum[i - 1]);
		}
		else if (v[i].length() >= 2 && v[i][0] == 'S' && v[i][1] == 'T') {
			unist[i] = addmod(unist[i], unisum[i - 1]);
		}
	}
	unistsum[0] = unist[0];
	for (int i = 1; i < n; i++) {
		unistsum[i] = addmod(unistsum[i - 1], unist[i]);
	}
	cout << unistsum[n - 1] % mod;
	return 0;
}