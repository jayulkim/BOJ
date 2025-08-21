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
    vector<vector<char>>Map(3 * 1025, vector<char>(6 * 1025, ' '));
    function<void(ll, ll, ll)> dfs = [&](ll a, ll b, ll c) -> void {
        if (a == 3) {
            Map[b][c + 2] = '*';
            Map[b + 1][c + 1] = '*';
            Map[b + 1][c + 3] = '*';
            for (int i = 0; i < 5; i++) {
                Map[b + 2][c + i] = '*';
            }
            return;
        }
        dfs(a / 2, b, c + a / 2);
        dfs(a / 2, b + a / 2, c);
        dfs(a / 2, b + a / 2, c + a);
        };
    dfs(n, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << Map[i][j];
        }
        cout << '\n';
    }
    return 0; 
}