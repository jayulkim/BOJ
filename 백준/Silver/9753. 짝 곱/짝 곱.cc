#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ary[100001];
vector<ll>v;
bool visited[100000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i * i <= 100000; i++) {
		if (!ary[i]) {
			for (int j = i * i; j <= 100000; j += i) {
				ary[j] = true;
			}
		}
	}
	for (ll i = 2; i <= 100000; i++) {
		if (!ary[i]) {
			v.push_back(i);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] * v[j] <= 100000000) {
				visited[v[i] * v[j]] = true;
			}
		}
	}
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0;
		cin >> n;
		for (int i = n; i <= 100000000; i++) {
			if (visited[i]) {
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}