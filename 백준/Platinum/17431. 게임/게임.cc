#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>result[300001];
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
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n;
		if (n == 1) {
			cout << '\n';
		}
		else if (n == 2) {
			cout << 'B' << '\n';
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (n - i < i) {
					break;
				}
				if (gcd(i, n - i) == 1) {
					mygcd(i, n - i, i);
					result[i].back()--;
				}
			}
			ll Min = LLONG_MAX;
			ll idx = -1;
			for (int i = 1; i <= n; i++) {
				if (n - i < i) {
					break;
				}
				if (!result[i].empty()) {
					ll sum = 0;
					for (auto& j : result[i]) {
						sum += j;
					}
					if (Min > sum) {
						Min = sum;
						idx = i;
					}
				}
			}
			string temp = "";
			ll count = 0;
			ll sum = 0;
			for (int j = result[idx].size() - 1; j >= 0; j--) {
				sum += result[idx][j];
				if (count % 2 == 0) {
					for (int k = 0; k < result[idx][j]; k++) {
						temp += 'B';
					}
				}
				else {
					for (int k = 0; k < result[idx][j]; k++) {
						temp += 'R';
					}
				}
				count++;
			}
			temp += 'R';
			cout << temp << '\n';
			for (int i = 1; i <= 300000; i++) {
				vector<ll>().swap(result[i]);
			}
		}
	}
	return 0;
}