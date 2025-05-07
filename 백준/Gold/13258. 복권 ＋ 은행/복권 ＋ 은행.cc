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
    vector<ld>v;
    ld sum = 0;
    for (int i = 0; i < n; i++) {
        ld num = 0;
        cin >> num;
        sum += num;
        v.push_back(num);
    }
    cin >> m >> k;
    cout << fixed;
    cout.precision(30);
    cout << v[0] + (v[0] / sum) * m * k;
    return 0;
}