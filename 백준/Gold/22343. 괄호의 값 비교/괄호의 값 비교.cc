#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll aa[1500001];
ll bb[1500001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		string a = "", b = "";
		cin >> a >> b;
		ll idx = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '(') {
				idx++;
			}
			else {
				idx--;
			}
			if (i > 0 && a[i - 1] == '(' && a[i] == ')') {
				aa[idx]++;
			}
		}
		for (int i = 1; i < 1500001; i++) {
			aa[i] += aa[i - 1] / 2;
			aa[i - 1] %= 2;
		}
		idx = 0;
		for (int i = 0; i < b.length(); i++) {
			if (b[i] == '(') {
				idx++;
			}
			else {
				idx--;
			}
			if (i > 0 && b[i - 1] == '(' && b[i] == ')') {
				bb[idx]++;
			}
		}
		for (int i = 1; i < 1500001; i++) {
			bb[i] += bb[i - 1] / 2;
			bb[i - 1] %= 2;
		}
		bool find = false;
		for (int i = 1500000; i >= 0; i--) {
			if (aa[i] > bb[i]) {
				cout << '>' << '\n';
				find = true;
				break;
			}
			else if (aa[i] < bb[i]) {
				cout << '<' << '\n';
				find = true;
				break;
			}
		}
		if (!find) {
			cout << '=' << '\n';
		}
		memset(aa, 0, sizeof(aa));
		memset(bb, 0, sizeof(bb));
	}
	return 0;
}