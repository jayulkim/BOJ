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
    priority_queue<ll>pq;
    for (int i = 0; i < n; i++) {
        cin >> m;
        pq.push(m);
    }
    ll result = 0;
    while (!pq.empty()) {
        if (pq.size() >= 2) {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            result += b;
            pq.push(a - b);
        }
        else {
            ll a = pq.top();
            pq.pop();
            result += a;
        }
    }
    if (result > 1440) {
        cout << -1;
        return 0;
    }
    cout << result;
    return 0;
}