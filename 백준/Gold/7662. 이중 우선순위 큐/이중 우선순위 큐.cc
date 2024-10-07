#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll>maxq;
priority_queue<ll, vector<ll>, greater<ll>>minq;
map<ll, int>m;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	while (num--) {
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char c;
			ll k = 0;
			cin >> c >> k;
			if (c == 'I') {
				maxq.push(k);
				minq.push(k);
				m[k]++;
			}
			else if (c == 'D') {
				if (k == 1) {
					while (!maxq.empty() && m[maxq.top()] == 0) {
						maxq.pop();
					}
					if (!maxq.empty()) {
						m[maxq.top()]--;
						maxq.pop();
					}
				}
				else if (k == -1) {
					while (!minq.empty() && m[minq.top()] == 0) {
						minq.pop();
					}
					if (!minq.empty()) {
						m[minq.top()]--;
						minq.pop();
					}
				}
			}
		}
		while (!maxq.empty() && m[maxq.top()] == 0) {
			maxq.pop();
		}
		while (!minq.empty() && m[minq.top()] == 0) {
			minq.pop();
		}
		if (maxq.empty() && minq.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			cout << maxq.top() << ' ' << minq.top() << '\n';
		}
		priority_queue<ll>().swap(maxq);
		priority_queue<ll, vector<ll>, greater<ll>>().swap(minq);
		map<ll, int>().swap(m);
	}
}