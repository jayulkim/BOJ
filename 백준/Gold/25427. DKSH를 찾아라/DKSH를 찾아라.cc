#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
ll d[100001];
ll dk[100001];
ll dks[100001];
ll dksh[100001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string str = "";
	cin >> str;
	for (int i = 1; i <= n; i++) {
		if (str[i - 1] == 'D') {
			d[i] = d[i - 1] + 1;
		}
		else {
			d[i] = d[i - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (str[i - 1] == 'K') {
			dk[i] = dk[i - 1] + d[i - 1];
		}
		else {
			dk[i] = dk[i - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (str[i - 1] == 'S') {
			dks[i] = dks[i - 1] + dk[i - 1];
		}
		else {
			dks[i] = dks[i - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (str[i - 1] == 'H') {
			dksh[i] = dksh[i - 1] + dks[i - 1];
		}
		else {
			dksh[i] = dksh[i - 1];
		}
	}
	cout << dksh[n];
	return 0;
}