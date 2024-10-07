#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>s;
vector<pair<int, int>>v;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end());
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (s.empty()) {
			s.push_back(v[i].second);
		}
		else {
			while (!s.empty() && s.back() > v[i].second) {
				count++;
				s.pop_back();
			}
			while (!s.empty() && s.back() == v[i].second) {
				s.pop_back();
			}
			s.push_back(v[i].second);
		}
	}
	while (!s.empty() && s.back() > 0) {
		count++;
		s.pop_back();
	}
	cout << count;
	return 0;
}