#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
ll Map[1001][1001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll sum = 0;
    ll Max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Map[i][j];
            sum += Map[i][j];
            Max = max(Max, Map[i][j]);
        }
    }
    if (!sum) {
        cout << 0;
        return 0;
    }
    ll start = 0, end = Max, mid = 0;
    ll Min = Max;
    while (start <= end) {
        mid = (start + end) / 2;
        ll temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp += min(Map[i][j], mid);
            }
        }
        if ((ld)temp / sum >= 0.5) {
            end = mid - 1;
            Min = min(Min, mid);
        }
        else {
            start = mid + 1;
        }
    }
    cout << Min;
    return 0;
}