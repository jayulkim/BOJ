#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll addmod(ll x, ll y, ll num) {
	if (x >= num - y) {
		return x - (num - y);
	}
	else {
		return x + y;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a = 0, b = 1;
	map<ll, ll>Map;
	Map[1] = 1;
	Map[0] = 0;
	for (int i = 2; i < 100001; i++) {
		ll sum = addmod(a, b, 1000000000000000000);
		Map[sum] = i;
		a = b;
		b = sum;
	}
	ll num = 0;
	cin >> num;
	while (num--) {
		string str = "";
		cin >> str;
		string temp = "";
		for (int i = str.length() - 1; i >= max((ll)0, (ll)str.length() - 18); i--) {
			temp += str[i];
		}
		reverse(temp.begin(), temp.end());
		cout << Map[stoll(temp)] << '\n';
	}
	return 0;
}