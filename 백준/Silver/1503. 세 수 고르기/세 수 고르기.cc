#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
bool visited[1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		visited[num] = true;
	}
	ll Min = 987654321;
	for (int i = 1; i <= 1001; i++) {
		for (int j = i; j <= 1001; j++) {
			for (int k = j; k <= 1001; k++) {
				if (!visited[i] && !visited[j] && !visited[k]) {
					Min = min(Min, llabs(i * j * k - n));
				}
			}
		}
	}
	cout << Min;
	return 0;
}