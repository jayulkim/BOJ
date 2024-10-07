#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	if (m == 1 || m == 2) {
		cout << "NEWBIE!";
	}
	else if (m != 1 && m != 2 && m <= n) {
		cout << "OLDBIE!";
	}
	else {
		cout << "TLE!";
	}
	return 0;
}