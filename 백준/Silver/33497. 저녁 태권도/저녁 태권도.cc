#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
char Map[101][101];
bool visited[101];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<pll>v;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    for (int i = 0; i < m; i++) {
        ll temp = n - v[i].first - v[i].second;
        if (temp < 0) {
            cout << "NO";
            return 0;
        }
        for (int j = 0; j < n && temp; j++) {
            if (!visited[j]) {
                Map[j][i] = 'X';
                visited[j] = true;
                temp--;
            }
        }
        for (int j = 0; j < n; j++) {
            if (Map[j][i] == '\0') {
                if (v[i].first) {
                    Map[j][i] = '+';
                    v[i].first--;
                }
                else if (v[i].second) {
                    Map[j][i] = '-';
                    v[i].second--;
                }
                else {
                    Map[j][i] = '+';
                    v[i].first--;
                }
            }
        }
        if (!(v[i].first <= 0 && v[i].second <= 0)) {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << Map[i][j];
        }
        cout << '\n';
    }
    return 0;
}