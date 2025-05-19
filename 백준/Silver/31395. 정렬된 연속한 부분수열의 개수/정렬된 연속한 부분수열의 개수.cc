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
    cin >> n;
    vector<ll>v;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
    }
    ll temp = 0;
    ll last = 0;
    ll result = 0;
    for (int i = 0; i < n; i++) {
        if (last < v[i]) {
            last = v[i];
            temp++;
        }
        else {
            result += temp * (temp + 1) / 2;
            temp = 1;
            last = v[i];
        }
    }
    result += temp * (temp + 1) / 2;
    cout << result;
    return 0;
}