#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
ll dp[1000001];
#define mod 1000000000
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[0] = 1;
    ll temp = 1;
    while (temp <= 1000000) {
        for (int i = temp; i <= 1000000; i++) {
            dp[i] += (dp[i - temp] % mod);
            dp[i] %= mod;
        }
        temp *= 2;
    }
    cin >> n;
    cout << dp[n] % mod;
    return 0; 
}