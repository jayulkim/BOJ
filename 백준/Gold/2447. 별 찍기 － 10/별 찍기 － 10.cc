#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
char Map[2201][2201];
void dfs(ll y, ll x, ll size) {
    if (size == 3) {
        for (int j = y; j <= y + size - 1; j++) {
            for (int k = x ; k <= x + size - 1; k++) {
                if (!(j == y + 1 && k == x + 1)) {
                    Map[j][k] = '*';
                }
            }
        }
        return;
    }
    dfs(y, x, size / 3);
    dfs(y + size / 3, x, size / 3);
    dfs(y + 2 * size / 3, x, size / 3);
    dfs(y, x + size / 3, size / 3);
    dfs(y, x + 2 * size / 3, size / 3);
    dfs(y + size / 3, x + 2 * size / 3, size / 3);
    dfs(y + 2 * size / 3, x + size / 3, size / 3);
    dfs(y + 2 * size / 3, x + 2 * size / 3, size / 3);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dfs(1, 1, n);
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            if (Map[j][k] == '\0') {
                cout << ' ';
            }
            else {
                cout << Map[j][k];
            }
        }
        cout << '\n';
    }
    return 0;
}