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
    cin >> n >> m >> k;
    vector<ll>a;
    vector<ll>b;
    vector<ll>c;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < m; i++) {
        ll num = 0;
        cin >> num;
        b.push_back(num);
    }
    for (int i = 0; i < k; i++) {
        ll num = 0;
        cin >> num;
        c.push_back(num);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll Min = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        auto aa = lower_bound(b.begin(), b.end(), a[i]);
        if (aa != b.end()) {
            auto bb = lower_bound(c.begin(), c.end(), *aa);
            if (bb != c.end()) {
                Min = min(Min, max({a[i], *aa, *bb}) - min({a[i], *aa, *bb}));
            }
        }
        aa = lower_bound(c.begin(), c.end(), a[i]);
        if (aa != b.end()) {
            auto bb = lower_bound(b.begin(), b.end(), *aa);
            if (bb != c.end()) {
                Min = min(Min, max({a[i], *aa, *bb}) - min({a[i], *aa, *bb}));
            }
        }
    }
    for (int i = 0; i < m; i++) {
        auto aa = lower_bound(a.begin(), a.end(), b[i]);
        if (aa != b.end()) {
            auto bb = lower_bound(c.begin(), c.end(), *aa);
            if (bb != c.end()) {
                Min = min(Min, max({b[i], *aa, *bb}) - min({b[i], *aa, *bb}));
            }
        }
        aa = lower_bound(c.begin(), c.end(), b[i]);
        if (aa != b.end()) {
            auto bb = lower_bound(a.begin(), a.end(), *aa);
            if (bb != c.end()) {
                Min = min(Min, max({b[i], *aa, *bb}) - min({b[i], *aa, *bb}));
            }
        }
    }
    for (int i = 0; i < k; i++) {
        auto aa = lower_bound(a.begin(), a.end(), c[i]);
        if (aa != b.end()) {
            auto bb = lower_bound(b.begin(), b.end(), *aa);
            if (bb != c.end()) {
                Min = min(Min, max({c[i], *aa, *bb}) - min({c[i], *aa, *bb}));
            }
        }
        aa = lower_bound(b.begin(), b.end(), c[i]);
        if (aa != b.end()) {
            auto bb = lower_bound(a.begin(), a.end(), *aa);
            if (bb != c.end()) {
                Min = min(Min, max({c[i], *aa, *bb}) - min({c[i], *aa, *bb}));
            }
        }
    }
    cout << Min;
    return 0;
}