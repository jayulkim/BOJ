#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<ll>v;
map<pll, int>Move = { {{1,3},4},{{3,1},4},{{2,4},4},{{4,2},4}, {{1,2},3},{{1,4},3},
    { {2,1},3},{{2,3},3},{{3,2},3},{{3,4},3},{{4,1},3},{{4,3},3} };
vector<vector<vector<ll>>>dp(100001, vector<vector<ll>>(5, vector<ll>(5, -1)));
ll dfs(ll depth, ll left, ll right) {
	if (depth == v.size()) {
		return 0;
	}
	if (dp[depth][left][right] != -1) {
		return dp[depth][left][right];
	}
	ll weight = LLONG_MAX;
	if (left == v[depth]) {
		weight = min(weight, dfs(depth + 1, v[depth], right) + 1);
	}
	else if (right == v[depth]) {
		weight = min(weight, dfs(depth + 1, left, v[depth]) + 1);
	}
	else {
		weight = min(weight, min(dfs(depth + 1, left, v[depth]) + Move[{right, v[depth]}], dfs(depth + 1, v[depth], right) + Move[{left, v[depth]}]));
	}
	return dp[depth][left][right] = weight;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 4; ++i)
	{
		Move[make_pair(0, i)] = 2;
	}
	while (1) {
		ll num = 0;
		cin >> num;
		if (!num) {
			break;
		}
		v.push_back(num);
	}
	cout << dfs(0, 0, 0);
	return 0;
}