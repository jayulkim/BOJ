#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
ll n = 0, m = 0, k = 0;
map<ll, ll>Map;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<ll>v;
    for (int i = 1; i <= m && v.size() < n; i++) {
        if (!Map[i]) {
            v.push_back(i);
            Map[i ^ k]++;
        }
    }
    if (v.size() < n) {
        cout << -1;
        return 0;
    }
    for (auto& i : v) {
        cout << i << ' ';
    }
    return 0;
}