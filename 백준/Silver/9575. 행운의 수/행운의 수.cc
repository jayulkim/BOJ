#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
bool visited[90001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	while (num--) {
		vector<ll>a;
		vector<ll>b;
		vector<ll>c;
		cin >> n;
		for (int i = 0; i < n; i++) {
			ll num = 0;
			cin >> num;
			a.push_back(num);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			ll num = 0;
			cin >> num;
			b.push_back(num);
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			ll num = 0;
			cin >> num;
			c.push_back(num);
		}
		ll count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int u = 0; u < k; u++) {
					ll temp = a[i] + b[j] + c[u];
					if (!visited[temp]) {
						visited[temp] = true;
						bool find = false;
						while (temp > 0) {
							if (temp % 10 != 5 && temp % 10 != 8) {
								find = true;
								break;
							}
							temp /= 10;
						}
						if (!find) {
							count++;
						}
					}
				}
			}
		}
		cout << count << '\n';
		memset(visited, false, sizeof(visited));
	}
	return 0; 
}