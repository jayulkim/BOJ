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
    vector<ll>v;
    for (int i = 0; i < 3; i++) {
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end(), greater<ll>());
    cout << v[0] * 2 - v[1] - v[2];
    return 0;
 } 