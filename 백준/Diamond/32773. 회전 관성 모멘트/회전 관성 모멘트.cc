#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
int main(void) {
    cin >> n;
    vector<pld>v;
    for (int i = 0; i < n; ++i) {
        ld x = 0, y = 0;
        cin >> x >> y;
        v.push_back({ x, y });
    }
    cout << fixed;
    cout.precision(1);
    ld a = 0;
    for (int i = 0; i < n; i++) {
        a += ((v[i].first * v[(i + 1) % n].second - v[i].second * v[(i + 1) % n].first) * ((v[i].first * v[i].first + v[i].first * v[(i + 1) % n].first + v[(i + 1) % n].first * v[(i + 1) % n].first + v[i].second * v[i].second + v[i].second * v[(i + 1) % n].second + v[(i + 1) % n].second * v[(i + 1) % n].second)));
    }
    cout << round((fabs(a) / 12.0) * 10) / 10.0;
    return 0;
}