#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
ll ary[26][100001];
ll sum[26][100001];
ll password[26];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		string a = "", b = "";
		cin >> a >> b;
		for (int i = 0; i < a.length(); i++) {
			ary[a[i] - 97][i]++;
		}
		for (int i = 0; i < 26; i++) {
			sum[i][0] = ary[i][0];
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 1; j < a.length(); j++) {
				sum[i][j] = sum[i][j - 1] + ary[i][j];
			}
		}
		for (auto& i : b) {
			password[i - 97]++;
		}
		bool Find = false;
		for (int i = 0; i < b.length(); i++) {
			if (password[b[i] - 97] != sum[b[i] - 97][b.length() - 1]) {
				Find = true;
				break;
			}
		}
		if (!Find) {
			cout << "YES" << '\n';
		}
		else {
			bool stop = false;
			for (int i = 1; i <= a.length() - b.length(); i++) {
				bool find = false;
				for (int j = 0; j < 26; j++) {
					if (password[j] != sum[j][i + b.length() - 1] - sum[j][i - 1]) {
						find = true;
						break;
					}
				}
				if (!find) {
					cout << "YES" << '\n';
					stop = true;
					break;
				}
			}
			if (!stop) {
				cout << "NO" << '\n';
			}
		}
		memset(ary, 0, sizeof(ary));
		memset(sum, 0, sizeof(sum));
		memset(password, 0, sizeof(password));
	}
	return 0;
}