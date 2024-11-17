#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>result[1000001];
ll gcd(ll a, ll b) {
	ll temp = a % b;
	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
	}
	return b;
}
void mygcd(ll a, ll b, ll i) {
	if (a < b) {
		swap(a, b);
	}
	ll temp = a % b;
	result[i].push_back(a / b);
	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
		if (a < b) {
			swap(a, b);	
		}
		result[i].push_back(a / b);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n == 1) {
		return 0;
	}
	else if (n == 2) {
		cout << 'X';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (n - i < i) {
			break;
		}
		if (gcd(i, n - i) == 1) {
			mygcd(i, n - i, i);
			result[i].back()--;
		}
	}
	vector<ll>vv;
	ll Min = LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		if (n - i < i) {
			break;
		}
		if (!result[i].empty() && result[i][0] >= 1) {
			ll sum = 0;
			for (auto& j : result[i]) {
				sum += j;
			}
			if (Min > sum) {
				Min = sum;
				vector<ll>().swap(vv);
				vv.push_back(i);
			}
			else if (Min == sum) {
				vv.push_back(i);
			}
		}
	}
	string str = "";
	for (int i = 1; i <= 1000000; i++) {
		str += 'Z';
	}
	for (auto& i : vv) {
		string temp = "";
		ll count = 0;
		ll sum = 0;
		for (int j = result[i].size() - 1; j >= 0; j--) {
			sum += result[i][j];
			if (count % 2 == 0) {
				for (int k = 0; k < result[i][j]; k++) {
					temp += 'X';
				}
			}
			else {
				for (int k = 0; k < result[i][j]; k++) {
					temp += 'Y';
				}
			}
			count++;
		}
		temp += 'X';
		if (temp < str) {
			str = temp;
		}
	}
	cout << str;
	return 0;
}