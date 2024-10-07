#include <bits/stdc++.h>
using namespace std;
char Map[10][10];
bool Find = false;
vector<pair<int, int>>v;
bool check(int y, int x) {
    for (int i = 0; i < 9; i++) {
        if (x != i && Map[y][x] == Map[y][i]) {
            return false;
        }
        if (y != i && Map[y][x] == Map[i][x]) {
            return false;
        }
    }
    for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++) {
        for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++) {
            if ((y != i || x != j) && Map[i][j] == Map[y][x]) {
                return false;
            }
        }
    }
    return true;
}
void dfs(int n) {
    if (Find) {
        return;
    }
    if (n == v.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << Map[i][j];
            }
            cout << '\n';
        }
        Find = true;
        return;
    }
    for (int i = 49; i <= 57; i++) {
        Map[v[n].first][v[n].second] = (char)i;
        if (check(v[n].first, v[n].second)) {
            dfs(n + 1);
        }
    }
    Map[v[n].first][v[n].second] = '0';
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == '0') {
                v.push_back({i, j});
            }
        }
    }
    dfs(0);
    return 0;
}