#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define len(str) str.length()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
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
vector<ll>v;
vector<ll>dp(1000001, -1);
ll dfs(ll a) {
    if (!a) {
        return 0;
    }
    if (dp[a] != -1) {
        return dp[a];
    }
    ll weight = 1e9;
    for (auto& i : v) {
        if (a - i >= 0) {
            weight = min(weight, dfs(a - i) + 1);
        }
    }
    return dp[a] = weight;
    };
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll temp = 1;
    ll add = 5;
    while (temp <= 1000000) {
        v.push_back(temp);
        temp += add;
        add += 4;
    }
    cin >> n;
    cout << dfs(n);
    return 0;
}