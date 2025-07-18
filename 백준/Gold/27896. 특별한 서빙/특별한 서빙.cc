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
    priority_queue<ll>pq;
    ll sum = 0;
    ll count = 0;
    for (int i = 0; i < n; i++) {
        ll a = 0;
        cin >> a;
        sum += a;
        pq.push(a);
        while (sum >= m) {
            sum -= 2 * pq.top();
            pq.pop();
            count++;
        }
    }
    cout << count;
    return 0;
 }