#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
vector<pair<ll, ll>>v;
vector<int>ary;
bool visited[21];
int result = 0, temp = -1;
ll score[100001];
ll Max = 0, t = 0;
void dfs(int size) {
	if (size == ary.size()) {
		for (int i = 0; i < v.size(); i++) {
			if (!visited[i]) {
				score[v[i].first]++;
			}
			else {
				score[v[i].second]++;
			}
			if (v[i].first != k) {
				Max = max(Max, score[v[i].first]);
			}
			if (v[i].second != k) {
				Max = max(Max, score[v[i].second]);
			}
		}
		for (int i = 0; i < v.size(); i++) {
			if ((v[i].first != k && score[v[i].first] >= score[k]) || (v[i].second != k && score[v[i].second] >= score[k])) {
				for (int j = 0; j < v.size(); j++) {
					if (!visited[j]) {
						score[v[j].first]--;
					}
					else {
						score[v[j].second]--;
					}
				}
				Max = t;
				return;
			}
		}
		if (score[k] > Max) {
			result++;
		}
		for (int i = 0; i < v.size(); i++) {
			if (!visited[i]) {
				score[v[i].first]--;
			}
			else {
				score[v[i].second]--;
			}
		}
		return;
	}
	for (int i = temp + 1; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			ary.push_back(i);
			temp = i;
			dfs(size);
			ary.pop_back();
			visited[i] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (c == 1) {
			score[a]++;
		}
		else if (c == 2) {
			score[b]++;
		}
		else {
			v.push_back({ a, b });
		}
	}
	for (int i = 1; i <= n; i++) {
		if (score[k] <= score[i] && k != i) {
			Max = max(Max, score[i]);
		}
	}
	t =  Max;
	for (int i = 0; i <= v.size(); i++) {
		dfs(i);
		temp = -1;
		Max = t;
	}
	cout << result;
	return 0;
}