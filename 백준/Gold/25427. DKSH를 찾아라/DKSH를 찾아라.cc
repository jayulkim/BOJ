#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
string str = "";
vector<vector<ll>>dp(100001, vector<ll>(5, -1));
string temp = "DKSH";
ll dfs(ll n, ll m) {
    if (m == temp.length()) {
        return 1;
    }
    if (n >= str.length()) {
        return 0;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }
    ll weight = 0;
    for (int i = n; i < str.length(); i++) {
        if (str[i] == temp[m]) {
            weight += dfs(i + 1, m + 1);
        }
    }
    return dp[n][m] = weight;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> str;
    cout << dfs(0, 0);
    return 0;
}