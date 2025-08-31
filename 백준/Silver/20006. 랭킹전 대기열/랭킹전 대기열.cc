#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
typedef pair<ll, string> pls;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<psl>>v(n + 1);
    ll idx = 0;
    for (int i = 0; i < n; i++) {
        ll a = 0;
        string str = "";
        cin >> a >> str;
        bool find = false;
        for (int j = 0; j < idx; j++) {
            if (v[j].size() < m) {
                if (v[j].empty()) {
                    v[j].push_back({ str, a });
                    find = true;
                    break;
                }
                if (llabs(v[j][0].second - a) <= 10) {
                    v[j].push_back({ str, a });
                    find = true;
                    break;
                }
            }
        }
        if (!find) {
            v[idx++].push_back({ str, a });
        }
    }
    for (int i = 0; i < idx; i++) {
        sort(v[i].begin(), v[i].end());
        if (v[i].size() == m) {
            cout << "Started!" << '\n';
        }
        else {
            cout << "Waiting!" << '\n';
        }
        for (auto& j : v[i]) {
            cout << j.second << ' ' << j.first << '\n';
        }
    }
    return 0;
}