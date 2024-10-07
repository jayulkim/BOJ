#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
ll n = 0, m = 0;
bool visited[200001];
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<ll>gift(n);
	for (int i = 0; i < n; i++) {
		cin >> gift[i];
	}
	vector<ll>box(n);
	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}
	sort(gift.begin(), gift.end());
	sort(box.begin(), box.end());
	for (int i = 0; i < n; i++) {
		Map[box[i]]++;
	}
	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		Map[num]--;
	}
	ll Max = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (Map[box[i]]) {
			Max = box[i];
			break;
		}
	}
	ll result = 0;
	for (int i = 0; i < n; i++) {
		if (gift[i] <= Max) {
			result = max(result, gift[i]);
		}
	}
	cout << result;
	return 0;
}