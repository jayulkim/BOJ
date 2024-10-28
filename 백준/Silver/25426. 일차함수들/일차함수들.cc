#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pair<ll, ll>>v;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end());
    ll result = 0;
    for (int i = n - 1; i >= 0; i--) {
        result += (v[i].first * (i + 1) + v[i].second);
    }
    cout << result;
    return 0;
}