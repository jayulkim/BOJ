#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	while (cin >> n) {
		string temp = "1";
		int count = 1;
		while (stoll(temp) % n != 0) {
			temp += '1';
			temp = to_string(stoll(temp) % n);
			count++;
		}
		cout << count << '\n';
	}
	return 0;
}