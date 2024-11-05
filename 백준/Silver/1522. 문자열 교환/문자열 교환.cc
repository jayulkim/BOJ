#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	cin >> str;
	ll a = 0;
	for (auto& i : str) {
		if (i == 'a') {
			a++;
		}
	}
	bool find = false;
	if (a > str.length() - a) {
		find = true;
		a = str.length() - a;
	}
	ll Min = LLONG_MAX;
	for (int i = 0; i < str.length(); i++) {
		ll b = 0, c = 0;
		for (int j = i; j < i + a; j++) {
			if (!find && str[j % str.length()] == 'b') {
				b++;
			}
			if (find && str[j % str.length()] == 'a') {
				c++;
			}
		}
		if (!find) {
			Min = min(Min, b);
		}
		else {
			Min = min(Min, c);
		}
	}
	cout << Min;
}