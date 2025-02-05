#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    map<string, ll>Map;
    for (int i = 0; i < n; i++) {
        string str = "";
        cin >> str;
        Map[str]++;
    }
    cin >> m;
    ll count = 0;
    for (int i = 0; i < m; i++) {
        string str = "";
        cin >> str;
        if (Map[str]) {
            count++;
        }
    }
    cout << count;
    return 0;
}