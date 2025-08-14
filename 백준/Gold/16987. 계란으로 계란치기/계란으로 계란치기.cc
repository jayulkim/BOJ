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
    cin >> n;
    vector<pll>v;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    ll result = 0;
    function<void(ll)> dfs = [&](ll a) -> void {
        if (a == n) {
            ll count = 0;
            for (int i = 0; i < n; i++) {
                if (v[i].first <= 0) {
                    count++;
                }
            }
            result = max(result, count);
            return;
        }
        if (v[a].first <= 0) {
            dfs(a + 1);
        }
        else {
            bool find = false;
            for (int i = 0; i < n; i++) {
                if (i != a && v[i].first > 0) {
                    find = true;
                    ll b = v[i].second;
                    ll c = v[a].second;
                    v[i].first -= c;
                    v[a].first -= b;
                    dfs(a + 1);
                    v[i].first += c;
                    v[a].first += b;
                }
            }
            if (!find) {
                dfs(n);
            }
        }
        };
    dfs(0);
    cout << result;
    return 0; 
}