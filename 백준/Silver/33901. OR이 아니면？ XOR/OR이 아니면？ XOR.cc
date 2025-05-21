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
    cin >> n >> m >> k;
    vector<ll>v;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
    }
    ll result = 0;
    vector<ll>Map(1 << 17, 0);
    for (int i = 0; i <= m; i++) {
        if (Map[v[i] ^ k]) {
            result += Map[v[i] ^ k];
        }
        Map[v[i]]++;
    }
    for (int i = m + 1; i < n; i++) {
        Map[v[i - m - 1]]--;
        if (Map[v[i] ^ k]) {
            result += Map[v[i] ^ k];
        }
        Map[v[i]]++;
    }
    cout << result;
    return 0;
}