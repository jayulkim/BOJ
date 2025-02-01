#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
bool compare(const pll& a, const pll& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pll>v;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ a / 2, b / 2 });
    }
    sort(v.begin(), v.end(), compare);
    ll temp = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first > temp) {
            sum += (v[i].first - temp) * v[i].second;
            temp = v[i].first;
        }
    }
    cout << sum * 4;
    return 0;
}