#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0, h = 0;
ll a[301][301];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> h;
    vector<vector<ll>>v(n + k, vector<ll>(m + h));
    for (int i = 0; i < n + k; i++) {
        for (int j = 0; j < m + h; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            a[i][j] = v[i][j];
        }
    }
    for (int i = k; i < n; i++) {
        for (int j = h; j < m; j++) {
            a[i][j] = v[i][j] - a[i - k][j - h];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}