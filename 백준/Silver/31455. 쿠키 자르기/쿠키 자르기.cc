#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
ll n = 0, m = 0, k = 0;
char Map[1025][1025];
ll dfs(ll y, ll x, ll size) {
    if (size == 1) {
        return Map[y][x] - '0';
    }
    ll sum = 0;
    ll a = 0, b = 0, c = 0, d = 0;
    for (int i = y; i < y + size / 2; i++) {
        for (int j = x; j < x + size / 2; j++) {
            a += (Map[i][j] - '0');
        }
    }
    for (int i = y; i < y + size / 2; i++) {
        for (int j = x + size / 2; j < x + size; j++) {
            b += (Map[i][j] - '0');
        }
    }
    for (int i = y + size / 2; i < y + size; i++) {
        for (int j = x; j < x + size / 2; j++) {
            c += (Map[i][j] - '0');
        }
    }
    for (int i = y + size / 2; i < y + size; i++) {
        for (int j = x + size / 2; j < x + size; j++) {
            d += (Map[i][j] - '0');
        }
    }
    ll temp = a + b + c + d;
    if (temp % 4 == 0) {
        sum += dfs(y, x + size / 2, size / 2);
        sum += dfs(y + size / 2, x, size / 2);
        sum += dfs(y + size / 2, x + size / 2, size / 2);
    }
    else if (temp % 4 == 1) {
        sum += dfs(y, x, size / 2);
        sum += dfs(y + size / 2, x, size / 2);
        sum += dfs(y + size / 2, x + size / 2, size / 2);
    }
    else if (temp % 4 == 2) {
        sum += dfs(y, x, size / 2);
        sum += dfs(y, x + size / 2, size / 2);
        sum += dfs(y + size / 2, x + size / 2, size / 2);
    }
    else if (temp % 4 == 3) {
        sum += dfs(y, x, size / 2);
        sum += dfs(y, x + size / 2, size / 2);
        sum += dfs(y + size / 2, x, size / 2);
    }
    return sum;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n;
        ll temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> Map[i][j];
                temp += (Map[i][j] - '0');
            }
        }
        cout << dfs(0, 0, n) << '\n';
    }
    return 0;
}