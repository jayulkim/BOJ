#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	if (num == 1) {
		cin >> n >> m;
		ll temp = n + m;
		string str = "";
		for (int i = 0; i < 13; i++) {
			str += (temp % 26 + 'a');
			temp /= 26;
		}
		cout << str;
	}
	else {
		string str = "";
		cin >> str;
		ll result = 0;
		ll count = 1;
		for (int i = 0; i < 13; i++) {
			result += (count * (str[i] - 'a'));
			count *= 26;
		}
		cout << result;
	}
	return 0;
}