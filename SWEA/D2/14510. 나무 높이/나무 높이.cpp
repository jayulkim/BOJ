#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef tuple<ll, ll, ll, ll, ll> lllll;
typedef tuple<ll, ll, vector<ll>> llv;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num = 0;
    cin >> num;
    ll count = 1;
    while (num--) {
        cin >> n;
        vector<ll>v;
        ll Max = 0;
        for (int i = 0; i < n; i++) {
            cin >> m;
            Max = max(Max, m);
            v.push_back(m);
        }
        vector<ll>t;
        for (int i = 0; i < n; i++) {
            t.push_back(Max - v[i]);
        }
        ll start = 0, end = 15000, mid = 0;
        ll Min = LLONG_MAX;
        while (start <= end) {
            mid = (start + end) / 2;
            ll a = (mid + 1) / 2;
            ll b = mid / 2;
            vector<ll>temp = t;
            bool find = false;
            for (auto& i : temp) {
                ll c = min(b, i / 2);
                i -= 2 * c;
                b -= c;
                ll d = min(i, a);
                i -= d;
                a -= d;
                if (i) {
                    find = true;
                    break;
                }
            }
            if (!find) {
                end = mid - 1;
                Min = min(Min, mid);
            }
            else {
                start = mid + 1;
            }
        }
        cout << '#' << count++ << ' ' << Min << '\n';
    }
    return 0;
 }