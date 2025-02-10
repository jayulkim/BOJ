#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
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
    ll Max = 1;
    vector<pll>up;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1]) {
            Max = 2;
            break;
        }
    }
    ll start = 0;
    while (1) {
        ll idx = -1;
        for (int i = start; i < n - 1; i++) {
            if (v[i] >= v[i + 1]) {
                if (i - start > 0) {
                    up.push_back({ start, i });
                }
                start = i + 1;
                idx = i;
                break;
            }
        }
        if (idx == -1 || idx == n - 2) {
            break;
        }
    }
    for (auto& i : up) {
        ll count = 0;
        for (int j = i.second + 1; j <= i.second + i.second - i.first; j++) {
            if (i.second - 1 - count >= 0 && j < n && v[i.second - 1 - count] == v[j]) {
                count++;
                Max = max(Max, count * 2 + 1);
            }
            else {
                break;
            }
        }
        count = 0;
        for (int j = i.second + 1; j <= i.second + i.second - i.first + 1; j++) {
            if (i.second - count >= 0 && j < n && v[i.second - count] == v[j]) {
                count++;
                Max = max(Max, count * 2);
            }
            else {
                break;
            }
        }
    }
    cout << Max;
    return 0;
}