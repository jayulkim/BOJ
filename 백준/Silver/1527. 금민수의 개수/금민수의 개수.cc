#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
string str = "47";
string graph = "";
vector<ll>result;
void dfs(int size) {
	if (graph.length() == size) {
		result.push_back(stoll(graph));
		return;
	}
	char temp = '0';
	for (int i = 0; i < 2; i++) {
		if (str[i] != temp) {
			graph.push_back(str[i]);
			temp = str[i];
			dfs(size);
			graph.pop_back();
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 9; i++) {
		dfs(i);
	}
	sort(result.begin(), result.end());
	cin >> n >> m;
	int left = lower_bound(result.begin(), result.end(), n) - result.begin();
	int right = upper_bound(result.begin(), result.end(), m) - result.begin();
	cout << right - left;
	return 0;
}