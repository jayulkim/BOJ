#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ary[50001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= 50000; i++) {
		if (!ary[i]) {
			for (int j = i * i; j <= 50000; j += i) {
				ary[j] = true;
			}
		}
	}
	vector<ll>v;
	for (int i = 2; i <= 50000; i++) {
		if (!ary[i]) {
			v.push_back(i);
		}
	}
	ll n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}