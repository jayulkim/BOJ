#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<ll>>dp(3001, vector<ll>(3001));
    string str = "";
    cin >> str;
    string a = "", b = "";
    ll Max = 0;
    for (int i = 0; i < str.length() / 2; i++) {
        a += str[i];
    }
    for (int i = str.length() / 2; i < str.length(); i++) {
        b += str[i];
    }
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + 1 });
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    Max = max(Max, (ll)min(a.length(), b.length()) - dp[a.length()][b.length()]);
    vector<vector<ll>>(3001, vector<ll>(3001)).swap(dp);
    a = "", b = "";
    for (int i = 0; i < str.length() / 2 + 1; i++) {
        a += str[i];
    }
    for (int i = str.length() / 2 + 1; i < str.length(); i++) {
        b += str[i];
    }
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + 1 });
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    Max = max(Max, (ll)min(a.length(), b.length()) - dp[a.length()][b.length()]);
    cout << Max;
    return 0;   
}