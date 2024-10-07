#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare(const string& a, const string& b) {
	return b + a < a + b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), compare);
	for (auto& i : v) {
		cout << i << ' ';
	}
	return 0;
}