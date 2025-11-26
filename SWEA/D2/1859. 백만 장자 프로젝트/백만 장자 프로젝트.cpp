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
        priority_queue<ll>pq;
        ll result = 0;
        for (int i = 0; i < n; i++) {
            cin >> m;
            v.push_back(m);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (!pq.empty()) {
                result += max((ll)0, pq.top() - v[i]);
            }
            pq.push(v[i]);
        }
        cout << '#' << count++ << ' ' << result << '\n';
    }
    return 0;
 }