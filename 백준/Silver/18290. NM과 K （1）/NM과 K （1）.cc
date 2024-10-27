#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
bool visited[11][11];
ll Map[11][11];
vector<ll>result;
ll Max = -LLONG_MAX;
ll n = 0, m = 0, k = 0;
ll Forward[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
void dfs(ll k) {
	if (result.size() == k) {
		ll sum = 0;
		for (auto& i : result) {
			sum += i;
		}
		Max = max(Max, sum);
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				bool find = false;
				for (int k = 0; k < 4; k++) {
					ll dy = i + Forward[k][0];
					ll dx = j + Forward[k][1];
					if (dy >= 0 && dy < n && dx >= 0 && dx < m && visited[dy][dx]) {
						find = true;
						break;
					}
				}
				if (!find) {
					visited[i][j] = true;
					result.push_back(Map[i][j]);
					dfs(k);
					visited[i][j] = false;
					result.pop_back();
				}	
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
		}
	}
	dfs(k);
	cout << Max;
	return 0;
}