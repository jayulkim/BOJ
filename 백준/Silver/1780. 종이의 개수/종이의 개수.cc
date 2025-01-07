#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll a = 0, b = 0, c = 0;
ll Map[2201][2201];
void dfs(ll y, ll x, ll size) {
    if (size == 1) {
        if (Map[y][x] == -1) {
            a++;
        }
        else if (!Map[y][x]) {
            b++;
        }
        else {
            c++;
        }
        return;
    }
    ll temp = Map[y][x];
    bool find = false;
    for (int i = y; i <= y + size - 1; i++) {
        for (int j = x; j <= x + size - 1; j++) {
            if (Map[i][j] != temp) {
                find = true;
                break;
            }
        }
        if (find) {
            break;
        }
    }
    if (!find) {
        if (temp == -1) {
            a++;
        }
        else if (!Map[y][x]) {
            b++;
        }
        else {
            c++;
        }
        return;
    }
    dfs(y, x, size / 3);
    dfs(y + size / 3, x, size / 3);
    dfs(y + 2 * size / 3, x, size / 3);
    dfs(y, x + size / 3, size / 3);
    dfs(y, x + 2 * size / 3, size / 3);
    dfs(y + size / 3, x + size / 3, size / 3);
    dfs(y + size / 3, x + 2 * size / 3, size / 3);
    dfs(y + 2 * size / 3, x + size / 3, size / 3);
    dfs(y + 2 * size / 3, x + 2 * size / 3, size / 3);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> Map[i][j];
        }
    }
    dfs(1, 1, n);
    cout << a << '\n';
    cout << b << '\n';
    cout << c << '\n';
    return 0;
}