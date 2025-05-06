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
    map<ll, ll>Map;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        Map[num]++;
        v.push_back(num);
    }
    vector<ll>result;
    for (int i = 1; i < n; i++) {
        ll d = v[i] - v[0];
        bool find = false;
        for (int j = 0; j < n; j++) {
            if (!Map[v[j] + d] && !Map[v[j] - d]) {
                find = true;
                break;
            }
        }
        if (!find) {
            result.push_back(d);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (auto& i : result) {
        cout << i << ' ';
    }
    return 0;
}