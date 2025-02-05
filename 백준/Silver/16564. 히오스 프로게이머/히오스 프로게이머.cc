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
    cin >> n >> m;
    vector<ll>v;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll start = 1, end = 2 * 1e9, mid = 0;
    ll Max = 0;
    while (start <= end) {
        mid = (start + end) / 2;
        ll temp = m;
        for (int i = 0; i < n; i++) {
            if (v[i] < mid) {
                temp -= mid - v[i];
            }
        }
        if (temp < 0) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
            Max = max(Max, mid);
        }
    }
    cout << Max;
    return 0;
}