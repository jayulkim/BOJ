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
    vector<ll>v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll Max = 1;
    for (int i = 0; i < n - 1; i++) {
        ll count = 1;
        ll temp = 0;
        for (int j = i + 1; j < n; j++) {
            if (v[i] != v[j]) {
                if (temp < m) {
                    temp++;
                }
                else {
                    Max = max(Max, count);
                    break;
                }
            }
            else {
                count++;
            }
            Max = max(Max, count);
        }
    }
    cout << Max;
    return 0;
 } 