//폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
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
    sort(v.begin(), v.end());
    vector<ll>sum(n + 1);
    sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + v[i];
    }
    for (int i = 0; i < m; i++) {
        ll num = 0;
        cin >> num;
        ll idx = lower_bound(v.begin(), v.end(), num) - v.begin();
        idx--;
        if (idx < 0) {
            cout << sum[n - 1] - n * num << '\n';
        }
        else if (idx == n - 1) {
            cout << n * num - sum[n - 1] << '\n';
        }
        else {
            cout << (idx + 1) * num - sum[idx] + sum[n - 1] - sum[idx] - (n - idx - 1) * num << '\n';
        }
    }
    return 0;
}