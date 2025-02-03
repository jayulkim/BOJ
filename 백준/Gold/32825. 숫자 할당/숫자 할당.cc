#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
ll aa = 0, bb = 0, cc = 0, dd = 0, ee = 0, ff = 0, gg = 0, hh = 0;
bool visited[14];
bool vv[14];
vector<ll>vvv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
vector<ll>v;
ll Count = 0;
void dfs() {
    if (v.size() == 6) {
        for (int i = 0; i < 6; i++) { 
            visited[v[i]] = true;
        }
        ll i = gg - v[4] - v[5], c = cc - v[3] - v[5];
        ll l = aa - v[0] - v[2] - i, d = ee - v[0] - v[1] - c;
        ll m = hh - l, h = dd - d;
        ll f = ff - v[2] - v[3] - h;
        bool find = false;
        if (ee != v[0] + v[1] + c + d) {
            find = true;
        }
        if (ff != v[2] + f + v[3] + h) {
            find = true;
        }
        if (gg != i + v[4] + v[5]) {
            find = true;
        }
        if (hh != l + m) {
            find = true;
        }
        if (aa != v[0] + v[2] + i + l) {
            find = true;
        }
        if (bb != v[1] + f + v[4] + m) {
            find = true;
        }
        if (cc != c + v[3] + v[5]) {
            find = true;
        }
        if (dd != d + h) {
            find = true;
        }
        if (i >= 1 && i <= 13) {
            if (visited[i]) {
                find = true;
            }
            visited[i] = true;
        }
        else {
            find = true;
        }
        if (c >= 1 && c <= 13) {
            if (visited[c]) {
                find = true;
            }
            visited[c] = true;
        }
        else {
            find = true;
        }
        if (l >= 1 && l <= 13) {
            if (visited[l]) {
                find = true;
            }
            visited[l] = true;
        }
        else {
            find = true;
        }
        if (d >= 1 && d <= 13) {
            if (visited[d]) {
                find = true;
            }
            visited[d] = true;
        }
        else {
            find = true;
        }
        if (m >= 1 && m <= 13) {
            if (visited[m]) {
                find = true;
            }
            visited[m] = true;
        }
        else {
            find = true;
        }
        if (h >= 1 && h <= 13) {
            if (visited[h]) {
                find = true;
            }
            visited[h] = true;
        }
        else {
            find = true;
        }
        if (f >= 1 && f <= 13) {
            if (visited[f]) {
                find = true;
            }
            visited[f] = true;
        }
        else {
            find = true;
        }
        if (!find) {
            Count++;
        }
        memset(visited, false, sizeof(visited));
        return;
    }
    for (int i = 0; i < 13; i++) {
        if (!vv[i]) {
            vv[i] = true;
            v.push_back(vvv[i]);
            dfs();
            vv[i] = false;
            v.pop_back();
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> aa >> bb >> cc >> dd >> ee >> ff >> gg >> hh;
    dfs();
    cout << Count;
    return 0;
}