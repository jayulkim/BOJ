#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll visited[300001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, m = 0, Max = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		visited[num]++;
		Max = max(Max, num);
	}
	ll count = 0;
	for (int i = 0; i < m; i++) {
		if (Max - 1 >= 0) {
			count += visited[Max];
			visited[Max - 1] += visited[Max];
			Max--;
		}
		else {
			break;
		}
	}
	cout << count;
	return 0;
}