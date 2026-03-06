#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define len(str) str.length()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<string, char, ll> scl;
typedef tuple<ll, ll, ll, ll> llll;
typedef tuple<ll, ll, ll, ll, ll> lllll;
typedef tuple<ll, ll, vector<ll>> llv;
typedef tuple<char, ll, ll> cll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
typedef pair<ll, string> pls;
typedef pair<ll, char> plc;
typedef pair<char, ll> pcl;
typedef pair<ll, vector<ll>> plv;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll mod = 1000000007;
    string str = "";
    cin >> str;
    vector<vector<ll>>dp(str.length() + 1, vector<ll>(3, -1));
    function<ll(ll, ll)> dfs = [&](ll a, ll b) -> ll {
        if (a == str.length()) {
            if (b == 2) {
                return 1;
            }
            return 0;
        }
        if (dp[a][b] != -1) {
            return dp[a][b];
        }
        ll weight = 0;
        weight += dfs(a + 1, b) % mod;
        weight %= mod;
        if (a + 1 < str.length()) {
            if (str[a + 1] - b - 'a' == 1) {
                weight += dfs(a + 1, b + 1) % mod;
                weight %= mod;
            }
            else if (str[a + 1] - b - 'a' == 0) {
                weight += dfs(a + 1, b) % mod;
                weight %= mod;
            }
        }
        return dp[a][b] = weight;
        };
    ll result = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a') {
            result += dfs(i, 0) % mod;
            result %= mod;
        }
    }
    cout << result;
    return 0;
}