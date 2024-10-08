#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> ti;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		ll n = 0;
		cin >> n;
		string str = "";
		cin >> str;
		string stack = "";
		for (int i = 0; i < n; i++) {
			stack += str[i];
			if (stack.length() < 3) {
				continue;
			}
			else {
				ll idx = stack.length() - 1;
				if (stack[idx] == 'B' && stack[idx - 1] == 'B' && stack[idx - 2] == 'A') {
					stack.pop_back();
					stack.pop_back();
					stack.pop_back();
					stack += 'B';
					idx = stack.length() - 1;
					ll count = 1;
					while (stack.length() >= 3 && stack[idx] == 'B' && stack[idx - 1] == 'B' && stack[idx - 2] == 'A') {
						stack.pop_back();
						stack.pop_back();
						stack.pop_back();
						stack += 'B';
						count++;
						idx = stack.length() - 1;
					}
					for (int j = 0; j < count; j++) {
						stack += 'A';
					}
				}
			}
		}
		cout << stack << '\n';
	}
	return 0;
}