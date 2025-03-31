#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll dist[101][101];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dist[i][j] = 1e9;
        }
    }
    for (int i = 1; i < n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> k;
            dist[i][k] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            for (int k = 1; k < n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((dist[1][i] != 1e9 || dist[1][j] != 1e9) && dist[i][j] != 1e9 && dist[j][i] != 1e9) {
                cout << "CYCLE";
                return 0;
            }
        }
    }
    cout << "NO CYCLE";
    return 0;
}